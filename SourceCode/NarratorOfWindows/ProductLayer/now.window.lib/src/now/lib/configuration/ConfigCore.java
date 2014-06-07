/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.configuration;

import now.lib.constant.NowConst;
import now.lib.utilities.UtilitiesFileXML;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * @author Chien Phan
 */
public class ConfigCore {
    private static ConfigCore m_instance = null;
    private final String m_fileConfig = NowConst.FILE_CONFIG_LANGUAGE;
    private final UtilitiesFileXML m_xmlFile;
    private final Document m_xmlDocument;
    
    private ConfigCore(){
        m_xmlFile = new UtilitiesFileXML(m_fileConfig);
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
    
    public static ConfigCore getInstance(){
        if(m_instance == null){
            m_instance = new ConfigCore();
        }
        return m_instance;
    }
    
    public String getConfig(String configName){
        String result = "";
        if(m_xmlDocument != null){
            Element root = m_xmlDocument.getDocumentElement();
            if(root != null){
                result = root.getElementsByTagName(configName).item(0).getTextContent();
            }
        }
        return result;
    }
    
    public void setConfig(String configName, String configValue){
        if(m_xmlDocument != null){
            Element root = m_xmlDocument.getDocumentElement();
            if(root != null){
                root.getElementsByTagName(configName).item(0).setTextContent(configValue);
            }
        }
        saveConfig();
    }
}
