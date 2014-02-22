package now.lib.translator;

import java.util.ArrayList;
import java.util.HashMap;

import now.lib.configuration.ConfigDefine;
import now.lib.configuration.ConfigTranslateEngine;
import now.lib.translator.engine.TranslatorEngineName;
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
		m_mapLangGoogleEngine = new HashMap<String, String>();
		UtilitiesFileTXT configFile = new UtilitiesFileTXT(ConfigDefine.FILE_CONFIG_LANGUAGE_CODE_GOOGLE);
		ArrayList<String[]> configData = configFile.readTextFile();
		for (String[] items : configData) {
			if(items.length == 2){
				m_mapLangGoogleEngine.put(items[0], items[1]);
			}
		}
	}
	
	private void initMapLangMicrosoftEngine(){
		m_mapLangMicrosoftEngine = new HashMap<String, String>();
		UtilitiesFileTXT configFile = new UtilitiesFileTXT(ConfigDefine.FILE_CONFIG_LANGUAGE_CODE_MICROSOFT);
		ArrayList<String[]> configData = configFile.readTextFile();
		for (String[] items : configData) {
			if(items.length == 2){
				m_mapLangMicrosoftEngine.put(items[0], items[1]);
			}
		}
	}
	
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
		if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(TranslatorEngineName.TRANSLATOR_ENGINE_GOOGLE)){
			result = m_mapLangGoogleEngine.get(languageName);
		}
		if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(TranslatorEngineName.TRANSLATOR_ENGINE_MICROSOFT)){
			result = m_mapLangMicrosoftEngine.get(languageName);
		}
		return result;
	}
}
