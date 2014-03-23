/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.display;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import now.lib.configuration.ConfigLanguage;
import now.lib.define.DefineDisplayCode;
import now.lib.utilities.UtilitiesDevice;
import now.lib.utilities.UtilitiesFileTXT;

/**
 *
 * @author Chien.Phan
 */
public class DisplayText {
    private static DisplayText m_instance = null;
    private HashMap<String, DisplayTextCollection> m_displayTextCollection = null;
    
    private DisplayText(){
        m_displayTextCollection = new HashMap<>();
        initDisplayTextCollection();
    }
    
    public static DisplayText getInstance(){
        if(m_instance == null){
            m_instance = new DisplayText();
        }
        return m_instance;
    }
    
    public String getText(String displayCode){
        String strResult = "N/A";
        HashMap<String, String> languageMap = new HashMap<>();
        
        if(m_displayTextCollection.containsKey(ConfigLanguage.getInstance().getDisplayLanguage())){
            languageMap = m_displayTextCollection.get(ConfigLanguage.getInstance().getDisplayLanguage()).getLanguageMap();
        }
        else{
            //Default case
            languageMap = m_displayTextCollection.get("English").getLanguageMap();
        }
        
        if(languageMap.containsKey(displayCode)){
            strResult = languageMap.get(displayCode);
        }
        return strResult;
    }

    private void initDisplayTextCollection() {
        //get current directory get all files
        ArrayList<String> files = UtilitiesDevice.getAllFile(new File (".\\language"));
        
        for (String file : files) {
            //check is language file (*.lang)
            if(file.endsWith("lang")){
                //read file's content
                UtilitiesFileTXT txtFile = new UtilitiesFileTXT(file);
                ArrayList<String[]> readTextFile = txtFile.readTextFile();
                
                //create data of display text
                String languageName = "";
                HashMap<String, String> languageData = new HashMap<>();

                for (String[] strings : readTextFile) {
                    if(strings.length == 2){
                        //process string
                        String tempCode = strings[0].trim().replaceAll("﻿", "");
                        String tempData = strings[1].trim().replaceAll("﻿", "");
                                                
                        if(tempCode.equals(DefineDisplayCode.LANGUAGE_NAME)){
                            languageName = tempData;
                        }
                        languageData.put(tempCode, tempData);
                    }
                } 
                
                if(!"".equals(languageName) && languageData.size() > 0){
                    DisplayTextCollection data = new DisplayTextCollection(languageName, languageData);
                    m_displayTextCollection.put(languageName, data);
                }
            }
        }
    }

    public String[] getListDisplayLanguage(){
        String[] result = new String[m_displayTextCollection.size()];
        int index = 0;
        for (Map.Entry<String, DisplayTextCollection> entry : m_displayTextCollection.entrySet()) {
            result[index] = entry.getKey();
            index++;
        }
        return result;
    }
}
