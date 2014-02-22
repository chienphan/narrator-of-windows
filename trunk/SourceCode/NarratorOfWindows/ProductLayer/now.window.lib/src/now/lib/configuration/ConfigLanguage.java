package now.lib.configuration;

import now.lib.utilities.UtilitiesFileXML;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

public class ConfigLanguage {
	private static ConfigLanguage m_instance = null;
	
	private String m_fileConfig = ConfigDefine.FILE_CONFIG_LANGUAGE;
	private UtilitiesFileXML m_xmlFile = null;
	private Document m_xmlDocument = null;
	
	private ConfigLanguage(){
		m_xmlFile = new UtilitiesFileXML(m_fileConfig);
		m_xmlDocument = m_xmlFile.getXMLDocument();
	};
	
	/**
	 * Save config to xml file
	 */
	private void saveConfig(){
		if(m_xmlFile != null)
		{
			m_xmlFile.writeXMLDocument();
		}
	}
	
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
		String result = "";
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				result = root.getElementsByTagName(ConfigDefine.LANGUAGE_CONFIG_OUTPUT).item(0).getTextContent();
			}
		}
		return result;
	}
	
	/**
	 * Get input language
	 * @return input language
	 */
	public String getInputLanguage() {
		String result = "";
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				result = root.getElementsByTagName(ConfigDefine.LANGUAGE_CONFIG_INPUT).item(0).getTextContent();
			}
		}
		return result;
	}
	
	/**
	 * Get display language
	 * @return display language
	 */
	public String getDisplayLanguage() {
		String result = "";
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				result = root.getElementsByTagName(ConfigDefine.LANGUAGE_CONFIG_DISPLAY).item(0).getTextContent();
			}
		}
		return result;
	}

	/**
	 * Set output language
	 * @param language language to save to config 
	 */
	public void setOutputLanguage(String language){
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				root.getElementsByTagName(ConfigDefine.LANGUAGE_CONFIG_OUTPUT).item(0).setTextContent(language);
			}
		}
		saveConfig();
	}
	
	/**
	 * Set input language
	 * @param language language to save to config 
	 */
	public void setInputLanguage(String language){
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				root.getElementsByTagName(ConfigDefine.LANGUAGE_CONFIG_INPUT).item(0).setTextContent(language);
			}
		}
		saveConfig();
	}

	/**
	 * Set display language
	 * @param language language to save to config 
	 */
	public void setDisplayLanguage(String language)
	{
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				root.getElementsByTagName(ConfigDefine.LANGUAGE_CONFIG_DISPLAY).item(0).setTextContent(language);
			}
		}
		saveConfig();
	}
}
