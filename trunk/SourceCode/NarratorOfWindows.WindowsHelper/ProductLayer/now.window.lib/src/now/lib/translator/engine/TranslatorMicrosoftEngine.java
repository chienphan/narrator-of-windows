package now.lib.translator.engine;

public class TranslatorMicrosoftEngine {
	private static TranslatorMicrosoftEngine m_instance = null;
	
	private TranslatorMicrosoftEngine(){
		
	}
	
	public static TranslatorMicrosoftEngine getInstance(){
		if(m_instance == null){
			m_instance = new TranslatorMicrosoftEngine();
		}
		return m_instance;
	}
	
	public String translate(String sentence, String languageInput, String languageOutput){
		return "This method is not implemented yet";
	}
}
