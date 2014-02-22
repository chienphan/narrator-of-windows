package now.lib.configuration;

import now.lib.utilities.UtilitiesFileXML;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

public class ConfigTranslateEngine {
	private static ConfigTranslateEngine m_instance = null;
	private Document m_xmlDocument = null;
	private UtilitiesFileXML m_xmlFile = null;
	
	private ConfigTranslateEngine()	{
		m_xmlFile = new UtilitiesFileXML(ConfigDefine.FILE_CONFIG_LANGUAGE);
		m_xmlDocument = m_xmlFile.getXMLDocument();
	}
	
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
	public String getTranslatorEngine()
	{
		String result = "";
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				result = root.getElementsByTagName(ConfigDefine.TRANSLATOR_ENGINE).item(0).getTextContent();
			}
		}
		return result;
	}
	
	/**
	 * Save config to xml file
	 * @param engineName Translator Engine name
	 */
	public void setTranslatorEngine(String engineName) {
		if(m_xmlDocument != null){
			Element root = m_xmlDocument.getDocumentElement();
			if(root != null){
				root.getElementsByTagName(ConfigDefine.TRANSLATOR_ENGINE).item(0).setTextContent(engineName);
			}
		}
		saveConfig();
	}
}
