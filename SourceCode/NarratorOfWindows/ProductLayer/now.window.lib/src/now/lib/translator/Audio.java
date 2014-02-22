package now.lib.translator;

import java.io.IOException;
import java.io.InputStream;

import javazoom.jl.decoder.JavaLayerException;
import now.lib.configuration.ConfigLanguage;

public class Audio {
	private static Audio m_instance = null;
	
	private Audio(){
		
	}
	
	public static Audio getInstance(){
		if(m_instance == null){
			m_instance = new Audio();
		}
		return m_instance;
	}
	
	public void play(String sentence){
		play(sentence, TranslatorLanguageManager.getInstance().getLanguageCode(ConfigLanguage.getInstance().getOutputLanguage()));
	}
	
	public void play(String sentence, String language){
		try {
			InputStream input = com.gtranslate.Audio.getInstance().getAudio(sentence, language);
			com.gtranslate.Audio.getInstance().play(input);
		} catch (IOException | JavaLayerException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
