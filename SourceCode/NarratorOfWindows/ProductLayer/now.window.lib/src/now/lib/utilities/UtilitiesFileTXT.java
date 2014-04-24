package now.lib.utilities;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class UtilitiesFileTXT {
    private String m_fileName = "";
    private final Charset ENCODING = StandardCharsets.UTF_8;

    public UtilitiesFileTXT(String fileName) {
            m_fileName = fileName;
    }
	
    /**
     * Read config text file
     * @return Array contain string config
     */
    public ArrayList<String[]> readTextFile(){ 
        ArrayList<String[]> result = new ArrayList<String[]>();
        String temp = "";
        String[] arrayTemp = null;
        Path path = Paths.get(m_fileName);

        Scanner scanner;
        try {
            scanner = new Scanner(path, ENCODING.name());
            while (scanner.hasNextLine()){
            //process each line in some way
            temp = scanner.nextLine();
            if(!temp.isEmpty()){
                arrayTemp = temp.split("=");
                if(arrayTemp.length == 2){
                    result.add(arrayTemp);
                }
            }
        }  
        scanner.close();
        } catch (IOException e) {
        }
        return result;
    }
	  
    public void writeLargerTextFile(String aFileName, ArrayList<String> aLines){
        BufferedWriter writer = null;
        try {
            Path path = Paths.get(aFileName);
            writer = Files.newBufferedWriter(path, ENCODING);
            for(String line : aLines){
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException ex) {
            Logger.getLogger(UtilitiesFileTXT.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                writer.close();
            } catch (IOException ex) {
                Logger.getLogger(UtilitiesFileTXT.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
