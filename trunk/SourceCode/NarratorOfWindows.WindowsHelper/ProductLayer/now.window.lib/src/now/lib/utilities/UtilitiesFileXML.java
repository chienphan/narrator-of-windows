package now.lib.utilities;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;
import org.xml.sax.SAXException;

import java.io.File;
import java.io.IOException;
 
/**
 * This class used to get XML document
 * @author Chien.Phan
 *
 */
public class UtilitiesFileXML {
	private String m_fileName = "";
	private File m_xmlFile = null;
	private Document m_xmlDocument = null;
	
	public UtilitiesFileXML(String filePath)	{
		m_fileName = filePath;
		m_xmlFile = new File(m_fileName);
		if(!m_fileName.isEmpty() && m_xmlFile.exists())
		{
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = null;
			try {
				dBuilder = dbFactory.newDocumentBuilder();
				m_xmlDocument = dBuilder.parse(m_xmlFile);
			} catch (ParserConfigurationException | SAXException | IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			//optional, but recommended
			//read this - http://stackoverflow.com/questions/13786607/normalization-in-dom-parsing-with-java-how-does-it-work
			m_xmlDocument.getDocumentElement().normalize();
		}
	}
	
	/**
	 * Get XML document from xml file
	 * @return xml document, null if file name is incorrectly
	 * @throws ParserConfigurationException
	 * @throws SAXException
	 * @throws IOException
	 */
	public Document getXMLDocument() {
		if(m_xmlDocument != null)
		{
			return m_xmlDocument;
		}
		return null;
	}
	
	/**
	 * Write xml document to file
	 * @throws IOException
	 * @throws TransformerException
	 */
	public void writeXMLDocument() {
		// Use a Transformer for output
		TransformerFactory tFactory = TransformerFactory.newInstance();
		DOMSource source = new DOMSource(m_xmlDocument);
		StreamResult result = new StreamResult(m_xmlFile);
		
		Transformer transformer = null;
		try {
			transformer = tFactory.newTransformer();
			transformer.transform(source, result);
		} catch (TransformerException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

