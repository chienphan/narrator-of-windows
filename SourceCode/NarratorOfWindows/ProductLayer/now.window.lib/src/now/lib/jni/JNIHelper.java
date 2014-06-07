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
        System.out.println("[getUIInformation]IN");
        String newSignature = "";
        try{
            newSignature = JNICaller.getInstance().getControlSignatureUnderMouse();
        }catch(Exception e){
            System.out.println("getUIInformation" + e.getMessage());
        }
        //Do not need check the control is changed or not. 
        //If the control is changed, the signature will not null.
        if(!newSignature.isEmpty())
        {
            System.out.println("[getUIInformation] newSignature: " + newSignature);
            if(!newSignature.equals(m_signature)){
                m_information = JNICaller.getInstance().getUIInformation(newSignature);
                m_signature = newSignature;
                System.out.println("[getUIInformation] information: " + m_information);
            }else{
                m_information = NowConst.NOW_EMPTY_STRING;
            }
        }else{
            m_information = NowConst.NOW_EMPTY_STRING;
        }
        System.out.println("[getUIInformation]OUT");
        return m_information;
    }
    
    public String getUIInformationForPressKey(){
        System.out.println("[getUIInformationForPressKey]IN");
        String signature = "";
        String information = "";
        try{
            signature = JNICaller.getInstance().getControlSignatureUnderMouse();
        }catch(Exception e){
            System.out.println("getUIInformation" + e.getMessage());
        }
        System.out.println("[getUIInformationForPressKey]signature=[" + signature + "]");
        if(!"".equals(signature))
        {
            
            information = JNICaller.getInstance().getUIInformation(signature);
            System.out.println("[getUIInformationForPressKey]information=" + information);
        }else{
            information = NowConst.NOW_EMPTY_STRING;
        }
        return information;
    }
}
