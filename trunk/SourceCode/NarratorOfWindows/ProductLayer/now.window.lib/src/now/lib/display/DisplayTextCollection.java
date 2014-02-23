/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.display;

import java.util.HashMap;

/**
 *
 * @author Administrator
 */
public class DisplayTextCollection {
    private String m_language = "";
    private HashMap<String, String> m_languageMap = null;
    
    public DisplayTextCollection(){
        m_languageMap = new HashMap<>();
    }
    
    public DisplayTextCollection(String languageName, HashMap<String, String> data){
        m_language = languageName;
        m_languageMap = data;
    }
    
    public String getLanguage() {
        return m_language;
    }

    public void setLanguage(String language) {
        this.m_language = language;
    }

    public HashMap<String, String> getLanguageMap() {
        return m_languageMap;
    }

    public void setLanguageMap(HashMap<String, String> languageMap) {
        this.m_languageMap = languageMap;
    }
}
