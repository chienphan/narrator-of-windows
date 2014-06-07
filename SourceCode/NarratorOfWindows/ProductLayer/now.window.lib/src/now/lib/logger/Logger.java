package now.lib.logger;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.logging.Level;

public class Logger {
    private static Logger m_instance = null;
    private static PrintWriter writer = null;
    private Logger(){
        
        
    }
    
    public static Logger getInstance(){
        if (m_instance == null) {
            m_instance = new Logger();
        }
        return m_instance;
    }
    
    public void log(String content){
        try {
            writer = new PrintWriter("c:\\java-log-file.txt", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException ex) {
            java.util.logging.Logger.getLogger(Logger.class.getName()).log(Level.SEVERE, null, ex);
        }
        writer.println(content);
        writer.flush();
        writer.close();
    }
}
