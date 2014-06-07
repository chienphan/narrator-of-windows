package now.lib.configuration;

import now.lib.constant.NowConst;

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
        return ConfigCore.getInstance().getConfig(NowConst.TRANSLATOR_ENGINE);
    }

    /**
     * Save config to xml file
     * @param engineName Translator Engine name
     */
    public void setTranslatorEngine(String engineName) {
        ConfigCore.getInstance().setConfig(NowConst.TRANSLATOR_ENGINE, engineName);
    }
}
