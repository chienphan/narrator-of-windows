/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.define;

import now.lib.translator.TranslatorLanguageManager;

/**
 *
 * @author Chien.Phan
 */
public class DefineLanguageName {
    public static final String[] getAllLanguageName(){
        return TranslatorLanguageManager.getInstance().getListLanguageName();
    }
}
