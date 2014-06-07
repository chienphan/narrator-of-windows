/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.configuration;

import now.lib.constant.NowConst;

/**
 *
 * @author Chien Phan
 */
public class ConfigCommon {
    private static ConfigCommon m_instance = null;
    
    private ConfigCommon(){
    }
    
    public static ConfigCommon getInstance(){
        if(m_instance == null){
            m_instance = new ConfigCommon();
        }
        return m_instance;
    }
    
    public boolean getAutoMoveMouse(){
        return ConfigCore.getInstance().getConfig(ConfigDefine.AUTO_MOVE_MOUSE).equals(NowConst.NOW_TRUE);
    }
    
    public boolean getAutoPlaySound(){
        return ConfigCore.getInstance().getConfig(ConfigDefine.AUTO_PLAY_SOUND).equals(NowConst.NOW_TRUE);
    }
    
    public boolean getAutoTranslate(){
        return ConfigCore.getInstance().getConfig(ConfigDefine.AUTO_TRANSLATE).equals(NowConst.NOW_TRUE);
    }
    
    public String getSpeed(){
        return ConfigCore.getInstance().getConfig(ConfigDefine.AUTO_SPEED);
    }
    
    public void setAutoMoveMouse(boolean isAuto){
        ConfigCore.getInstance().setConfig(ConfigDefine.AUTO_MOVE_MOUSE, isAuto ? NowConst.NOW_TRUE : NowConst.NOW_FALSE);
    }
    
    public void setAutoPlaySound(boolean isAuto){
        ConfigCore.getInstance().setConfig(ConfigDefine.AUTO_PLAY_SOUND, isAuto ? NowConst.NOW_TRUE : NowConst.NOW_FALSE);
    }
    
    public void setAutoTranslate(boolean isAuto){
        ConfigCore.getInstance().setConfig(ConfigDefine.AUTO_TRANSLATE, isAuto ? NowConst.NOW_TRUE : NowConst.NOW_FALSE);
    }
    
    public void setSpeed(String speedLevel){
        ConfigCore.getInstance().setConfig(ConfigDefine.AUTO_SPEED, speedLevel);
    }
}
