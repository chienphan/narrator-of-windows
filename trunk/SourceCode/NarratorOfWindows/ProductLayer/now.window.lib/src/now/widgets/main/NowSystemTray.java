/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import java.util.logging.Level;
import java.util.logging.Logger;
import now.lib.configuration.ConfigCommon;
import now.lib.configuration.ConfigDefine;
import now.lib.configuration.ConfigLanguage;
import now.lib.define.DefineDisplayCode;
import now.lib.display.DisplayText;
import now.lib.jni.JNIHelper;
import now.lib.translator.Audio;
import now.lib.translator.Translator;
import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.ImageData;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Tray;
import org.eclipse.swt.widgets.TrayItem;
import org.jnativehook.GlobalScreen;
import org.jnativehook.NativeHookException;
import org.jnativehook.keyboard.NativeKeyEvent;
import org.jnativehook.keyboard.NativeKeyListener;

/**
 *
 * @author Chien.Phan
 */
public class NowSystemTray implements NativeKeyListener {
    private static NowSystemTray m_instance = null;
    
    //The display
    private Display     m_display          = null;
    
    //Shells
    private Shell       m_systemTrayShell  = null;
    //private Shell       configShell        = null;
    
    //Image of system tray icon
    private ImageData   m_imageData        = null;
    private Image       m_image            = null;
    
    //The system tray
    private Tray        m_tray             = null;
    private TrayItem    m_itemTray         = null;
    
    //The popup menu
    private Menu        m_popupMenu        = null;
    private MenuItem    m_menuConfigWindow = null;
    private MenuItem    m_separator        = null;
    private MenuItem    m_menuClose        = null;
    private MenuItem    m_menuMainWindow   = null;
    
    private NowSystemTray(){
        //Create display and init the shell
        m_display               = new Display();
	m_systemTrayShell       = new Shell(m_display);
        
        m_tray                  = m_display.getSystemTray();
        if (m_tray == null) {
            System.out.println("The system tray is not available");
        } 
        else {
            m_imageData             = new ImageData(ConfigDefine.FILE_IMAGE_TRAY_ICON);
            m_image                 = new Image(m_display, m_imageData);
            m_itemTray              = new TrayItem(m_tray, SWT.NONE);
            m_popupMenu             = new Menu(m_systemTrayShell, SWT.POP_UP);
            m_menuMainWindow        = new MenuItem(m_popupMenu, SWT.PUSH);
            m_menuConfigWindow      = new MenuItem(m_popupMenu, SWT.PUSH);
            m_separator             = new MenuItem(m_popupMenu, SWT.SEPARATOR);
            m_menuClose             = new MenuItem(m_popupMenu, SWT.PUSH);
            
            //init listener
            initListener();
            //init content
            initContent();
            //init mouse event
            listenMouseMoveEvent();
            
            NowInformationWindow.getInstance().initWindow(m_display);
        }
    }
    
    private void listenMouseMoveEvent(){
        Thread thread = new Thread(new Runnable() {

            @Override
            public void run() {
                while(!m_systemTrayShell.isDisposed()){
                    if(ConfigCommon.getInstance().getAutoMoveMouse() == true){
                        getSupportedInformation();
                    }
                    try {   
                        Thread.sleep(100);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(NowSystemTray.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        });
        
        thread.start();
    }
    
    private void initListener(){
        //Open the config window
        m_menuConfigWindow.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                NowConfigurationWindow.getInstance().showWindow(m_display);
            }
        });
        
        //Open main window
        m_menuMainWindow.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                NowMainWindow.getInstance().showWindow(m_display);
            }
        });
        
        //Close the app
        m_menuClose.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                GlobalScreen.unregisterNativeHook();
                m_itemTray.dispose();
                System.exit(0);
            }
        });
        
        //Click right mouse 
        m_itemTray.addListener(SWT.MenuDetect, new Listener() {
            @Override
            public void handleEvent(Event event) {
                updateContent();
                m_popupMenu.setVisible(true);
            }
        });
            
        //Click left mouse
        m_itemTray.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                updateContent();
                m_popupMenu.setVisible(true);
            }
        });
    }
    
    private void initContent(){
        //Set tooltip for tray icon
        updateContent();
        m_itemTray.setImage(m_image);
        m_popupMenu.setDefaultItem(m_menuMainWindow);
    }
    
    private void updateContent(){
        m_itemTray.setToolTipText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_CLICK_SHOW_MENU));
        m_menuConfigWindow.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_CONFIGURATION));
        m_menuClose.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_EXIT));
        m_menuMainWindow.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_MAIN_WINDOW));
    }
    
    private void beginKeyboardListener(){
        try {
            GlobalScreen.registerNativeHook();
        }
        catch (NativeHookException ex) {
            System.err.println("There was a problem registering the native hook.");
            System.err.println(ex.getMessage());

            System.exit(1);
        }

        //Construct the example object and initialze native hook.
        GlobalScreen.getInstance().addNativeKeyListener(NowSystemTray.getInstance());
    }
    
    public static NowSystemTray getInstance(){
        if(m_instance == null){
            m_instance = new NowSystemTray();
        }
        return m_instance;
    }
        
    public void showSystemTray(){
        //Show main ưindow 
        NowMainWindow.getInstance().showWindow(m_display);
        
        beginKeyboardListener();
        while (!m_systemTrayShell.isDisposed()) {
          if (!m_display.readAndDispatch())
            m_display.sleep();
        }
        GlobalScreen.unregisterNativeHook();
        m_image.dispose();
        m_display.dispose();
    }
    
    private void getSupportedInformation(){
        Display.getDefault().syncExec(new Runnable() {

            @Override
            public void run() {
                if (ConfigCommon.getInstance().getAutoPlaySound() == true) {
                    String infor = JNIHelper.getInstance().getUIInformation();
                    if(!infor.isEmpty()){
                        //Check config auto play sound
                        String outString = "";
                        //Check config auto translate
                        if(ConfigCommon.getInstance().getAutoTranslate() == true){
                            outString = Translator.getInstance().translateAutoDetectInput(infor);
                            Audio.getInstance().play(outString);
                            System.out.println("Speak AutoTranslate: " + outString);
                        }else{
                            Audio.getInstance().play(infor, ConfigLanguage.getInstance().getInputLanguage());
                            System.out.println("Speak : " + infor);
                        }
                    }
                }
                //else{
                    //NowInformationWindow.getInstance().showWindow(m_display);
                //}
            }
        });
    }

    @Override
    public void nativeKeyPressed(NativeKeyEvent e) {
        //Check for the pressed key
        if(ConfigCommon.getInstance().getAutoMoveMouse() == false){
            if (e.getKeyCode() == NativeKeyEvent.VK_CONTROL){
                getSupportedInformation();
            }
        }
    }

    @Override
    public void nativeKeyReleased(NativeKeyEvent e) {
        //System.out.println("Key Released: " + NativeKeyEvent.getKeyText(e.getKeyCode()));
    }

    @Override
    public void nativeKeyTyped(NativeKeyEvent e) {
        //System.out.println("Key Typed: " + e.getKeyText(e.getKeyCode()));
    }
}
