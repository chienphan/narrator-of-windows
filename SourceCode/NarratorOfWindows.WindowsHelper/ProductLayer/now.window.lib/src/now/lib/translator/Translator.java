package now.lib.translator;

import now.lib.configuration.ConfigLanguage;
import now.lib.configuration.ConfigTranslateEngine;
import now.lib.define.DefineEngineName;
import now.lib.translator.engine.TranslatorGoogleEngine;

public class Translator {
	private static Translator m_instance = null;
			
	private Translator(){
		
	}

    /**
     *Get instance of class
     * @return instance of Translator
     */
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
	
	/**
	 * Translate auto detect input and out language (using config)
	 * @param sentence contain to translate
	 * @return sentence after translate
	 */
	public String translateAutoDetectInput(String sentence){
		return translateAutoDetectInput(sentence, ConfigLanguage.getInstance().getOutputLanguage());
	}
	
	/**
	 * Translate auto detect input language (using config)
	 * @param sentence contain to translate
	 * @param languageOutput language output
	 * @return sentence after translate
	 */
	public String translateAutoDetectInput(String sentence, String languageOutput){
		String result = "";
		if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(DefineEngineName.TRANSLATOR_ENGINE_GOOGLE)){
			result = TranslatorGoogleEngine.getInstance().translate(
					sentence, 
					TranslatorLanguageManager.getInstance().getLanguageCode(ConfigLanguage.getInstance().getInputLanguage()), 
					TranslatorLanguageManager.getInstance().getLanguageCode(languageOutput));
		}
		if(ConfigTranslateEngine.getInstance().getTranslatorEngine().equalsIgnoreCase(DefineEngineName.TRANSLATOR_ENGINE_MICROSOFT)){
			//http://msdn.microsoft.com/en-us/library/ff512437.aspx
			result = "This method is not implemented yet";
		}
		return result;
	}
}
