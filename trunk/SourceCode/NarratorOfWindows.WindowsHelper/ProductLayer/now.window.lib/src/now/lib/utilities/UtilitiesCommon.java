/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.utilities;

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
}
