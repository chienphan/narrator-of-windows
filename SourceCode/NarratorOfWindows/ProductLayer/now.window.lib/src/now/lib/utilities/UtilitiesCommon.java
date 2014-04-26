/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.utilities;

import java.util.ArrayList;

/**
 *
 * @author Chien Phan
 */
public class UtilitiesCommon {
    /**
     * get index of @input in @arrayString
     * @param arrayString
     * @param input
     * @return 
     */
    public static int getIndex(String[] arrayString, String input){
        int index = -1;
        for (int i = 0; i < arrayString.length; i++) {
            if(input.equals(arrayString[i])){
                index = i;
                break;
            }
        }
        return index;
    }

    public static String getLessonName(String path) {
        UtilitiesFileTXT file = new UtilitiesFileTXT(path);
        ArrayList<String[]> data = file.readTextFile();
        
        for (String[] strings : data) {
            if(strings.length == 2){
                if (strings[0].equals("lesson_name")) {
                    return strings[1];
                }
            }
        }
        return "";
    }
    
    public static String getLessonNo(String path) {
        UtilitiesFileTXT file = new UtilitiesFileTXT(path);
        ArrayList<String[]> data = file.readTextFile();
        
        for (String[] strings : data) {
            if(strings.length == 2){
                if (strings[0].equals("lesson_no")) {
                    return strings[1];
                }
            }
        }
        return "";
    }
    
    public static String getLessonDescription(String path) {
        UtilitiesFileTXT file = new UtilitiesFileTXT(path);
        ArrayList<String[]> data = file.readTextFile();
        
        for (String[] strings : data) {
            if(strings.length == 2){
                if (strings[0].equals("lesson_description")) {
                    return strings[1];
                }
            }
        }
        return "";
    }
}
