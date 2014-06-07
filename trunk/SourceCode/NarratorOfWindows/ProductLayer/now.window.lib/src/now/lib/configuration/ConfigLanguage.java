package now.lib.configuration;

import now.lib.constant.NowConst;

public class ConfigLanguage {
    private static ConfigLanguage m_instance = null;
    
    private ConfigLanguage(){
        
    };

    /**
     * Get single-ton instance
     * @return single-ton instance of ConfigLanguage
     */
    public static ConfigLanguage getInstance(){
        if(m_instance == null){
            m_instance = new ConfigLanguage();
        }
        return m_instance;
    }

    /**
     * Get output language
     * @return output language
     */
    public String getOutputLanguage() {
        return ConfigCore.getInstance().getConfig(NowConst.LANGUAGE_CONFIG_OUTPUT);
    }

    /**
     * Get input language
     * @return input language
     */
    public String getInputLanguage() {
        return ConfigCore.getInstance().getConfig(NowConst.LANGUAGE_CONFIG_INPUT);
    }

    /**
     * Get display language
     * @return display language
     */
    public String getDisplayLanguage() {
        return ConfigCore.getInstance().getConfig(NowConst.LANGUAGE_CONFIG_DISPLAY);
    }

    /**
     * Set output language
     * @param language language to save to config 
     */
    public void setOutputLanguage(String language){
        ConfigCore.getInstance().setConfig(NowConst.LANGUAGE_CONFIG_OUTPUT, language);
    }

    /**
     * Set input language
     * @param language language to save to config 
     */
    public void setInputLanguage(String language){
        ConfigCore.getInstance().setConfig(NowConst.LANGUAGE_CONFIG_INPUT, language);
    }

    /**
     * Set display language
     * @param language language to save to config 
     */
    public void setDisplayLanguage(String language) {
        ConfigCore.getInstance().setConfig(NowConst.LANGUAGE_CONFIG_DISPLAY, language);
    }
}
