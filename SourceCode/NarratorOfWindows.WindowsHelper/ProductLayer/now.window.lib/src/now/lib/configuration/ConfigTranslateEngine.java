package now.lib.configuration;

public class ConfigTranslateEngine {
    private static ConfigTranslateEngine m_instance = null;

    private ConfigTranslateEngine() {

    }

    /**
     * Get single-ton instance
     * @return single-ton instance of ConfigTranslateEngine
     */
    public static ConfigTranslateEngine getInstance() {
        if(m_instance == null){
            m_instance = new ConfigTranslateEngine();
        }
        return m_instance;
    }

    /**
     * Get translator engine
     * @return translator engine
     */
    public String getTranslatorEngine() {
        return ConfigCore.getInstance().getConfig(ConfigDefine.TRANSLATOR_ENGINE);
    }

    /**
     * Save config to xml file
     * @param engineName Translator Engine name
     */
    public void setTranslatorEngine(String engineName) {
        ConfigCore.getInstance().setConfig(ConfigDefine.TRANSLATOR_ENGINE, engineName);
    }
}
