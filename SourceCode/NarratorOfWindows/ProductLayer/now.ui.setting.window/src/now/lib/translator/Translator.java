package now.lib.translator;

import java.util.HashMap;

import now.lib.configuration.ConfigLanguage;
import now.lib.configuration.ConfigTranslateEngine;

public class Translator {
	public static final class TranslatorEngineName {
		public static final String TRANSLATOR_ENGINE_GOOGLE 	= "Google";
		public static final String TRANSLATOR_ENGINE_MICROSOFT 	= "Microsoft";
	}
	
	public static final class TranslatorLanguageName{
		public static final String VIETNAMESE 	= "Vietnamese";
		public static final String ENGLISH 		= "English";
	}
	
	private static Translator m_instance = null;
	private String m_languageInput 	= "";
	private String m_languageOutput = "";
	private String m_engineName 	= "";
	
	private HashMap<String, String> m_mapLangGoogleEngine = null;
	private HashMap<String, String> m_mapLangMicrosoftEngine = null;
	
	private void initMapLangGoogleEngine(){
		m_mapLangGoogleEngine = new HashMap<String, String>();
		m_mapLangGoogleEngine.put(TranslatorLanguageName.VIETNAMESE, com.gtranslate.Language.VIETNAMESE);
		m_mapLangGoogleEngine.put(TranslatorLanguageName.ENGLISH, com.gtranslate.Language.ENGLISH);
	}
	
	private void initMapLangMicrosoftEngine(){
		m_mapLangMicrosoftEngine = new HashMap<String, String>();
	}
	
	private Translator(){
		m_languageInput 	= ConfigLanguage.getInstance().getInputLanguage();
		m_languageOutput 	= ConfigLanguage.getInstance().getOutputLanguage();
		m_engineName 		= ConfigTranslateEngine.getInstance().getTranslatorEngine();
		initMapLangGoogleEngine();
		initMapLangMicrosoftEngine();
	}
	
	private String translateAutoDetectInputUsingGoogleEngine(String sentence){
		return "";
	}
	
	public static Translator getInstance(){
		if(m_instance == null){
			m_instance = new Translator();
		}
		return m_instance;
	}
	
	public String translate(String sentence, String languageInput){
		return "This method is not implemented yet";
	}
	
	public String translate(String sentence, String languageInput, String languageOutput){
		return "This method is not implemented yet";
	}
	
	public String translateAutoDetectInput(String sentence){
		String result = "";
		if(m_engineName.equalsIgnoreCase(TranslatorEngineName.TRANSLATOR_ENGINE_GOOGLE)){
			result = com.gtranslate.Translator.getInstance().translate(sentence, 
					m_mapLangGoogleEngine.get(m_languageInput), m_mapLangGoogleEngine.get(m_languageOutput));
		}
		return result;
	}
	
	public String translateAutoDetectInput(String sentence, String languageOutput){
		return "This method is not implemented yet";
	}
}
