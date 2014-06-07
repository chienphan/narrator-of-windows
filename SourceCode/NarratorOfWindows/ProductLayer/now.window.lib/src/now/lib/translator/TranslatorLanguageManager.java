package now.lib.translator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import now.lib.configuration.ConfigTranslateEngine;
import now.lib.constant.NowConst;
import now.lib.define.DefineEngineName;
import now.lib.utilities.UtilitiesFileTXT;

public class TranslatorLanguageManager {
    private static TranslatorLanguageManager m_instance = null;
    private HashMap<String, String> m_mapLangGoogleEngine = null;
    private HashMap<String, String> m_mapLangMicrosoftEngine = null;

    private TranslatorLanguageManager(){
        initMapLangGoogleEngine();
        initMapLangMicrosoftEngine();
    }
	
    private void initMapLangGoogleEngine(){
        m_mapLangGoogleEngine = new HashMap<>();
        UtilitiesFileTXT configFile = new UtilitiesFileTXT(NowConst.FILE_CONFIG_LANGUAGE_CODE_GOOGLE);
        ArrayList<String[]> configData = configFile.readTextFile();
        for (String[] items : configData) {
            if(items.length == 2){
                m_mapLangGoogleEngine.put(items[0], items[1]);
            }
        }
    }

    private void initMapLangMicrosoftEngine(){
        m_mapLangMicrosoftEngine = new HashMap<>();
        UtilitiesFileTXT configFile = new UtilitiesFileTXT(NowConst.FILE_CONFIG_LANGUAGE_CODE_MICROSOFT);
        ArrayList<String[]> configData = configFile.readTextFile();
        for (String[] items : configData) {
            if(items.length == 2){
                m_mapLangMicrosoftEngine.put(items[0], items[1]);
            }
        }
    }

    /**
     *Get instance of class
     * @return instance of TranslatorLanguageManager
     */
    public static TranslatorLanguageManager getInstance(){
        if(m_instance == null){
            m_instance = new TranslatorLanguageManager();
        }
        return m_instance;
    }
	
    /**
     * Get language code from language name (using TranslatorEngineName config)
     * @param languageName name of language
     * @return the code
     */
    public String getLanguageCode(String languageName){
        String result = "";
        if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(DefineEngineName.TRANSLATOR_ENGINE_GOOGLE)){
            result = m_mapLangGoogleEngine.get(languageName);
        }
        if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(DefineEngineName.TRANSLATOR_ENGINE_MICROSOFT)){
            result = m_mapLangMicrosoftEngine.get(languageName);
        }
        return result;
    }
    
    public String[] getListLanguageName(){
        String[] result = new String[m_mapLangGoogleEngine.size()];
        int index = 0;
        if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(DefineEngineName.TRANSLATOR_ENGINE_GOOGLE)){
//            result = new String[m_mapLangGoogleEngine.size()];
//            for (Map.Entry<String, String> entry : m_mapLangGoogleEngine.entrySet()) {
//                result[index] = entry.getKey();
//                index++;
//            }
            ArrayList<String> arrayList = new ArrayList<>();
            for (Map.Entry<String, String> entry : m_mapLangGoogleEngine.entrySet()) {
                arrayList.add(entry.getKey());
            }
            Collections.sort(arrayList);
            if(arrayList.size() > 0){
                for (Iterator<String> it = arrayList.iterator(); it.hasNext();) {
                    result[index] = it.next();
                    index++;
                }
            }
        }else if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(DefineEngineName.TRANSLATOR_ENGINE_MICROSOFT)){
            System.err.println("This method is not implemented yet");
        }
        return result;
    }
}
