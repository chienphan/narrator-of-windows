package now.lib.utilities;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class UtilitiesDevice {
	
    /** Get value of Environment Variable
     * @author Chien.Phan
     * @param strVariable Environment Variable
     * @return Value of environment variable
     */
    public static String getEnvironmentVariableValue(String strVariable) {
        return System.getenv(strVariable);
    }

    /** Get current directory 
     * @author Chien.Phan
     * 
     * @return current directory
     */
    public static String getCurrentDirectory()
    {
        File directory = new File (".");
        try {
            return directory.getCanonicalPath().toString();
        } catch (IOException e) {
            System.err.println("\n[getCurrentDirectory] exception: " + e.getMessage()); 
        }
        return "";
    }

    /** Dynamic loading library
     * 
     * @param strFullFilePath
     * @return true if succeed, false if exception
     * 
     * @author Chien.Phan
     */
    public static boolean loadLibrary(String strFullFilePath) {
        try {
            System.load(strFullFilePath);
        } catch (Exception e) {
            System.err.println("\n[LoadLibrary] exception: " + e.getMessage()); 
            return false;
        }
        System.out.println("\n[loadLibrary] ok!!"); 
        return true;
    }

    public static ArrayList<String> getAllFile(File directory){
        ArrayList<String> result = new ArrayList<>();
        for (final File fileEntry : directory.listFiles()) {
            if (fileEntry.isFile()) {
                result.add(fileEntry.getPath());
            }
        }
        return result;
    }
}
