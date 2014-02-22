package now.lib.translator.engine;

import java.util.ArrayList;
import java.util.HashMap;

import now.lib.utilities.UtilitiesStringProcessor;

public class TranslatorGoogleEngine {
	private static TranslatorGoogleEngine m_instance = null;
	
	private TranslatorGoogleEngine(){
		
	}
	
	public static TranslatorGoogleEngine getInstance() {
		if(m_instance == null){
			m_instance = new TranslatorGoogleEngine();
		}
		return m_instance;
	}
	
	/**
	 * Translate sentence using Google Translate API
	 * @param sentence content to translate
	 * @param languageInput language input
	 * @param languageOutput language output
	 * @return the sentence after translate
	 */
	public String translate(String sentence, String languageInput, String languageOutput){
		String result = "";
		//Split input string to prepare to translate
		ArrayList<HashMap<Boolean, String>> textToTranslate = UtilitiesStringProcessor.split(sentence);
		for (HashMap<Boolean, String> hashMap : textToTranslate) {
			if(hashMap.size() == 1){
				//We only need to translate if string is not a punctuation
				if(hashMap.containsKey(true)){
					result += com.gtranslate.Translator.getInstance().translate(hashMap.get(true).trim(), languageInput, languageOutput);
				}
				//This case for punctuation
				if(hashMap.containsKey(false)){
					result += hashMap.get(false) + " ";
				}
			}
		}
		
		return result;
	}

}
