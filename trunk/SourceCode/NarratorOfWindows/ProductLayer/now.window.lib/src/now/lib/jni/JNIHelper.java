/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.jni;

import now.lib.constant.NowConst;

/**
 *
 * @author gobom
 */
public class JNIHelper {
    private static JNIHelper m_instance = null;
    private String m_signature = NowConst.NOW_EMPTY_STRING;
    private String m_information = NowConst.NOW_NOT_AVAILABLE;
    private JNIHelper(){
        
    }
    
    public static JNIHelper getInstance(){
        if(m_instance == null){
            m_instance = new JNIHelper();
        }
        return m_instance;
    }
    
    public String getUIInformation(){
        String newSignature = JNICaller.getInstance().getControlSignatureUnderMouse();
        //Do not need check the control is changed or not. 
        //If the control is changed, the signature will not null.
        if(!newSignature.isEmpty())
        {
            if(!newSignature.equals(m_signature)){
                m_information = JNICaller.getInstance().getUIInformation(newSignature);
                m_signature = newSignature;
            }
        }
        
        return m_information;
    }
}
