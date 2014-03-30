/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import now.lib.configuration.ConfigCommon;
import now.lib.configuration.ConfigLanguage;
import now.lib.constant.NowConst;
import now.lib.define.DefineDisplayCode;
import now.lib.define.DefineLanguageName;
import now.lib.display.DisplayText;
import now.lib.jni.JNIHelper;
import now.lib.translator.Audio;
import now.lib.translator.Translator;
import now.lib.utilities.UtilitiesCommon;
import now.lib.utilities.UtilitiesDevice;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.StyledText;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;

import org.jnativehook.GlobalScreen;
import org.jnativehook.keyboard.NativeKeyEvent;
import org.jnativehook.keyboard.NativeKeyListener;
import org.jnativehook.mouse.NativeMouseEvent;
import org.jnativehook.mouse.NativeMouseInputListener;

/**
 *
 * @author gobom
 */
public class NowInformationWindow implements NativeMouseInputListener, NativeKeyListener {
    private static NowInformationWindow m_instance = null;
    
    private Shell       m_shell         = null;
    private Combo       m_cboLanguage   = null;
    private StyledText  m_txtInfor      = null;
    private Button      m_btnPlay       = null;
    private Button      m_btnTranslate  = null;
    private Composite   m_cmpContainer  = null;
    private Composite   m_cmpLeft       = null;
    private Composite   m_cmpRight      = null;
    private GridLayout  m_gridLayoutMain    = null;
    private GridLayout  m_gridLayoutSecond    = null;
    
    //private RowLayout   m_rowLayout     = null;
    private GridLayout  m_gridLayoutButton  = null;
    private GridData    m_gridDataButton    = null;
    private GridData    m_gridDataMain      = null;
    private GridData    m_gridDataSecond      = null;
            
    private String      m_strOriginalInfor = NowConst.NOW_EMPTY_STRING;
    private double      m_nDistance     = 0.0;
    private Rectangle   m_rectwindow    = null;
    private Point       m_pointWindow   = null;
    
    private boolean m_isOutWindow = true;
    /**
     * Constructor
     */
    private NowInformationWindow(){
        
    }
    
    /**
     * Initialize Information Window
     */
    private void initializeWindow(){
        String[] listLanguageName = DefineLanguageName.getAllLanguageName();
        m_gridLayoutMain = new GridLayout();
        m_gridLayoutMain.numColumns = 1;
        
        Point currentMousePoint = m_shell.getDisplay().getCursorLocation();
        m_shell.setSize(NowConst.NOW_INFOR_WINDOW_WIDTH, NowConst.NOW_INFOR_WINDOW_HEIGHT);
        m_shell.setLayout(m_gridLayoutMain);
        //m_shell.setLocation(new Point(currentMousePoint.x + 20, currentMousePoint.y + 20));
              
        m_gridDataMain = new GridData();
        m_gridDataMain.horizontalAlignment = GridData.FILL;
        m_gridDataMain.grabExcessHorizontalSpace = true;
        m_gridDataMain.widthHint = 450;
        m_gridDataMain.heightHint = 100;
            
        m_txtInfor = new StyledText (m_shell, SWT.MULTI | SWT.WRAP);
        m_txtInfor.setLayoutData(m_gridDataMain);
        m_txtInfor.setSize(440, 50);
        
        m_gridLayoutSecond = new GridLayout();
        m_gridLayoutSecond.numColumns = 2;
        
        m_gridDataSecond = new GridData();
        m_gridDataMain.widthHint = 100;
        
        m_cmpContainer = new Composite(m_shell, SWT.NONE);
        m_cmpContainer.setLayoutData(m_gridDataMain);
        m_cmpContainer.setLayout(m_gridLayoutSecond);
        
        m_cmpLeft = new Composite(m_cmpContainer, SWT.NONE);
        m_cmpLeft.setLayoutData(m_gridDataSecond);
        m_cboLanguage = new Combo(m_cmpLeft, SWT.READ_ONLY);
        m_cboLanguage.setBounds(0, 0, 150, 65);
        m_cboLanguage.setItems(listLanguageName);
        m_cboLanguage.select(UtilitiesCommon.getIndex(listLanguageName, 
                ConfigLanguage.getInstance().getOutputLanguage()));
        
        m_cmpRight = new Composite(m_cmpContainer, SWT.NONE);
        
        m_gridLayoutButton = new GridLayout();
        m_gridLayoutButton.numColumns = 2;
        m_gridDataButton = new GridData();
        m_gridDataButton.heightHint = NowConst.NOW_BUTTON_HEIGHT;
        m_gridDataButton.widthHint = NowConst.NOW_BUTTON_WIDTH;
        
        m_cmpRight.setLayout(m_gridLayoutButton);
        
        //m_rowLayout = new RowLayout();
        //m_rowLayout.pack = false;
        //m_cmpRight.setLayout(m_rowLayout);
        
        m_btnTranslate = new Button(m_cmpRight, SWT.PUSH);
        m_btnTranslate.setLayoutData(m_gridDataButton);
        //m_btnTranslate.setText("Translate");
        
        m_btnPlay = new Button(m_cmpRight, SWT.PUSH);
        m_btnPlay.setLayoutData(m_gridDataButton);
        //m_btnPlay.setText("Play");
        
        if(ConfigCommon.getInstance().getAutoTranslate() == true){
            
            Display.getDefault().syncExec(new Runnable() {

                @Override
                public void run() {
                    String outString = Translator.getInstance().translateAutoDetectInput(m_strOriginalInfor);
                    if(!outString.isEmpty()){
                        m_txtInfor.setText(outString);
                    }else{
                        m_txtInfor.setText(m_strOriginalInfor);
                    }
                }
            });
        }else{
            m_txtInfor.setText(m_strOriginalInfor);
        }
        
        updateContent();
    }
        
    /**
     * Initialize distance of mouse cursor location and window
     */
    private void initializeDistance(){
        
        m_pointWindow = new Point(m_shell.getLocation().x + m_shell.getSize().x / 2, m_shell.getLocation().y + m_shell.getSize().y / 2);
        Point mousePoint = m_shell.getDisplay().getCursorLocation();
        m_nDistance = getDistance(m_pointWindow, mousePoint);
    }
    
    /**
     * Calculate distance between two point
     * @param pointA
     * @param pointB
     * @return the distance
     */
    private double getDistance(Point pointA, Point pointB){
        return Math.sqrt((pointA.x - pointB.x)*(pointA.x - pointB.x) 
                            + (pointA.y - pointB.y)*(pointA.y - pointB.y));
    }
    
    /**
     * initialize mouse move listener
     */
    private void initializeMouseMoveListener(){
        GlobalScreen.getInstance().addNativeMouseMotionListener(NowInformationWindow.getInstance());
        GlobalScreen.getInstance().addNativeKeyListener(NowInformationWindow.getInstance());
    }
    
    /**
     * Initialize Button Listener
     */
    private void initializeButtonListener() {
        m_btnTranslate.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                String languageName = m_cboLanguage.getText();
                ConfigLanguage.getInstance().setOutputLanguage(languageName);
                String strAfterTranslate = Translator.getInstance().translateAutoDetectInput(m_strOriginalInfor);
                m_txtInfor.setText(strAfterTranslate);
            }
        });
        
        m_btnPlay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                String languageName = m_cboLanguage.getText();
                ConfigLanguage.getInstance().setOutputLanguage(languageName);
                String strAfterTranslate = Translator.getInstance().translateAutoDetectInput(m_strOriginalInfor);
                Audio.getInstance().play(strAfterTranslate);
            }
        });
    }
    
    private void updateInforFormShell(){
        final Point locationWindow = calculateLocation(m_shell.getDisplay().getCursorLocation());
        
        Display.getDefault().syncExec(new Runnable() {

                @Override
                public void run() {
                    m_shell.setLocation(new Point(locationWindow.x, locationWindow.y));
                }
        });
        
        //This case for "Automation translate to output language"
        if(ConfigCommon.getInstance().getAutoTranslate() == true){
            Display.getDefault().syncExec(new Runnable() {

                @Override
                public void run() {
                    //m_shell.setLocation(new Point(currentMousePoint.x + 20, currentMousePoint.y + 20));
                    String outString = Translator.getInstance().translateAutoDetectInput(m_strOriginalInfor);
                    if(!outString.isEmpty()){
                        m_txtInfor.setText(outString);
                    }else{
                        m_txtInfor.setText(m_strOriginalInfor);
                    }
                }
            });
        }
        //This case is not translate
        else{
            Display.getDefault().syncExec(new Runnable() {

                @Override
                public void run() {
                    m_txtInfor.setText(m_strOriginalInfor);
                }
            });
        }
    }
    
    private void updateContent(){
        m_btnTranslate.setText(DisplayText.getInstance().getText(DefineDisplayCode.WINDOW_INFOR_BUTTON_TRANSLATE));
        m_btnPlay.setText(DisplayText.getInstance().getText(DefineDisplayCode.WINDOW_INFOR_BUTTON_PLAY));
    }
    
    /**
     * Get instance of NowInformationWindow class
     * @return the instance
     */
    public static NowInformationWindow getInstance(){
        if(m_instance == null){
            m_instance = new NowInformationWindow();
        }  
        return m_instance;
    }
    
    /**
     * Translate auto detect input and out language (using configuration)
     * @param display current display
     * @param information information to display in Information Window
     */
    public void showWindow(Display display){
        if(m_shell == null){
            //Create new shell
            m_shell = new Shell(display, SWT.BORDER_DASH | SWT.ON_TOP);
            initializeWindow();
            m_shell.open();
            initializeDistance();
            m_rectwindow = new Rectangle(m_shell.getLocation().x, m_shell.getLocation().y, m_shell.getSize().x, m_shell.getSize().y);
            
            initializeButtonListener();
            m_shell.setVisible(false);
            
            System.out.println("setVisible true lan dau");
            
            initializeMouseMoveListener();
            
        }
    }

    @Override
    public void nativeMouseMoved(NativeMouseEvent e) {
        //This case for "Automatic Move mouse" and "display information window" mode
        if(ConfigCommon.getInstance().getAutoMoveMouse() == true
                && ConfigCommon.getInstance().getAutoPlaySound() == false){
            if(isMousePointerOutOfInformationWindow() == true){
                final String infor = JNIHelper.getInstance().getUIInformation();
                if(!infor.isEmpty()){
                    Display.getDefault().syncExec(new Runnable() {

                        @Override
                        public void run() {
                            m_strOriginalInfor = infor;
                            updateInforFormShell();
                            updateContent();
                            m_shell.setVisible(true);
                            System.out.println("setVisible true");
                            
                            initializeDistance();
                            //Update new bounding rectangle of window
                            m_rectwindow = new Rectangle(m_shell.getLocation().x, 
                                                            m_shell.getLocation().y, 
                                                            m_shell.getSize().x, 
                                                            m_shell.getSize().y);
                        }
                    });
                }
            }
        }
        
        //Check to close the window
        if(!m_shell.isDisposed()){
            Point mousePoint = new Point(e.getX(), e.getY());
            //Condition to close Information Window
            if(!m_rectwindow.contains(mousePoint) && (getDistance(m_pointWindow, mousePoint)  > (m_nDistance + 50.0))){
                Display.getDefault().syncExec(new Runnable() {
                    
                    @Override
                    public void run() {
                        m_shell.setVisible(false);
                    }
                });
            }
        }
    }
    
    @Override
    public void nativeMouseDragged(NativeMouseEvent e) {
    }

    @Override
    public void nativeMouseClicked(NativeMouseEvent e) {
    }

    @Override
    public void nativeMousePressed(NativeMouseEvent e) {
    }

    @Override
    public void nativeMouseReleased(NativeMouseEvent e) {
    }

    @Override
    public void nativeKeyPressed(NativeKeyEvent e) {
        //Check for the pressed key
        if(ConfigCommon.getInstance().getAutoMoveMouse() == false){
            if (e.getKeyCode() == NativeKeyEvent.VK_CONTROL){
                final String infor = JNIHelper.getInstance().getUIInformationForPressKey();
                if(!infor.isEmpty()){
                    
                    Display.getDefault().syncExec(new Runnable() {

                        @Override
                        public void run() {
                            
                            m_strOriginalInfor = infor;
                            updateInforFormShell();
                            updateContent();
                            m_shell.setVisible(true);
                            
                            initializeDistance();
                            m_rectwindow = new Rectangle(m_shell.getLocation().x, m_shell.getLocation().y, m_shell.getSize().x, m_shell.getSize().y);
                        }
                    });
                }
            }
        }
    }

    @Override
    public void nativeKeyReleased(NativeKeyEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void nativeKeyTyped(NativeKeyEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private boolean isMousePointerOutOfInformationWindow() {
        m_isOutWindow = true;
        Display.getDefault().syncExec(new Runnable() {

            @Override
            public void run() {
                Point mousePoint = m_shell.getDisplay().getCursorLocation();
                if(m_shell.getBounds().contains(mousePoint)){
                    m_isOutWindow = false;
                }
            }
        });
        
        return m_isOutWindow;
    }

    private Point calculateLocation(Point cursorLocation) {
        Point screenResolution = UtilitiesDevice.getScreenResolution();
        System.out.println("Resolution=" + screenResolution.toString());
        Point resultPoint = cursorLocation;
        //calculate the position of window to display
        if(cursorLocation.x > screenResolution.x - NowConst.NOW_INFOR_WINDOW_WIDTH){
            resultPoint.x -= (NowConst.NOW_INFOR_WINDOW_WIDTH + 10);
        } else {
            resultPoint.x += 10;
        }
        if(cursorLocation.y > screenResolution.y - NowConst.NOW_INFOR_WINDOW_HEIGHT){
            resultPoint.y -= (NowConst.NOW_INFOR_WINDOW_HEIGHT + 10);
        } else {
            resultPoint.y += 10;
        }
        return resultPoint;
    }
}
