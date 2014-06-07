package now.lib.translator;

import java.io.IOException;
import java.io.InputStream;

import javazoom.jl.decoder.JavaLayerException;
import now.lib.configuration.ConfigLanguage;

public class Audio {
    private static Audio m_instance = null;

    private Audio(){

    }

    private void playWithLanguageCode(String sentence, String languageCode){
        try {
            InputStream input = com.gtranslate.Audio.getInstance().getAudio(sentence, languageCode);
                com.gtranslate.Audio.getInstance().play(input);
        } catch (IOException | JavaLayerException e) {
            System.err.println("[playWithLanguageCode] execption: " + e.getMessage());
        }
    }

    public static Audio getInstance(){
        if(m_instance == null){
            m_instance = new Audio();
        }
        return m_instance;
    }

    public void play(String sentence){
        playWithLanguageCode(sentence, TranslatorLanguageManager.getInstance().getLanguageCode(ConfigLanguage.getInstance().getOutputLanguage()));
    }

    public void play(String sentence, String language){
        String languageCode = TranslatorLanguageManager.getInstance().getLanguageCode(language);
        if(!languageCode.isEmpty()){
            try {
                InputStream input = com.gtranslate.Audio.getInstance().getAudio(sentence, languageCode);
                    com.gtranslate.Audio.getInstance().play(input);
            } catch (IOException | JavaLayerException e) {
                System.err.println("[playWithLanguageCode] execption: " + e.getMessage());
            }
        }
    }
}
