/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import now.lib.configuration.ConfigCommon;
import now.lib.configuration.ConfigLanguage;
import now.lib.configuration.ConfigTranslateEngine;
import now.lib.constant.NowConst;
import now.lib.define.DefineDisplayCode;
import now.lib.define.DefineEngineName;
import now.lib.define.DefineLanguageName;
import now.lib.display.DisplayText;
import now.lib.utilities.UtilitiesCommon;
import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.ImageData;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Monitor;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Text;

/**
 *
 * @author Administrator
 */
public class NowConfigurationWindow {
    private NowConfigurationWindow(){
    }
    /**
     * Set bounding rectangle of config window
     * @param display Display contain config window
     */
    private void setDisplayPointAtCenterScreen(Display display){
        if(m_shell != null){
            Monitor primary = display.getPrimaryMonitor ();
            Rectangle bounds = primary.getBounds ();
            Rectangle rect = m_shell.getBounds ();
            int x = bounds.x + (bounds.width - rect.width) / 2;
            int y = bounds.y + (bounds.height - rect.height) / 2;
            m_shell.setLocation (x, y);
        }
    }
    
    private void initializeWindow() {
        m_shell.setSize(NowConst.NOW_CONFIG_WINDOW_WIDTH, NowConst.NOW_CONFIG_WINDOW_HEIGHT);
        
        initializeMainFrame();
        initializeGeneralTab();
        initializeTranslateTab();
        initializeDisplayTab();
        initializeListener();
        
        updateContent();
    }
    
    private void initializeListener(){
        //Click button
        m_btnCancel.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                Display.getDefault().syncExec(new Runnable() {

                    @Override
                    public void run() {
                        m_shell.dispose();
                    }
                });
            }
        });
    
        m_btnOK.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                Display.getDefault().syncExec(new Runnable() {

                    @Override
                    public void run() {
                        //TODO: save configuration here!!!!!!
                        ConfigLanguage.getInstance().setDisplayLanguage(m_comboDisplay.getText());
                        ConfigLanguage.getInstance().setInputLanguage(m_comboInputLanguage.getText());
                        ConfigLanguage.getInstance().setOutputLanguage(m_comboOutputLanguage.getText());
                        ConfigTranslateEngine.getInstance().setTranslatorEngine(m_comboEngineTranslate.getText());
                        
                        if(m_radioOperationAuto.getSelection()){
                            ConfigCommon.getInstance().setAutoMoveMouse(true);
                        }else{
                            ConfigCommon.getInstance().setAutoMoveMouse(false);
                        }
                        
                        if(m_radioModePlay.getSelection()){
                            ConfigCommon.getInstance().setAutoPlaySound(true);
                        }else{
                            ConfigCommon.getInstance().setAutoPlaySound(false);
                        }
                        
                        if(m_checkAutoTranslate.getSelection()){
                            ConfigCommon.getInstance().setAutoTranslate(true);
                        }else{
                            ConfigCommon.getInstance().setAutoTranslate(false);
                        }
                        NowMainWindow.getInstance().updateWidgetsContent();
                        //Close window
                        m_shell.dispose();
                    }
                });
            }
        });
        
        m_btnApply.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                Display.getDefault().syncExec(new Runnable() {

                    @Override
                    public void run() {
                        //TODO: save configuration here!!!!!!
                        ConfigLanguage.getInstance().setDisplayLanguage(m_comboDisplay.getText());
                        ConfigLanguage.getInstance().setInputLanguage(m_comboInputLanguage.getText());
                        ConfigLanguage.getInstance().setOutputLanguage(m_comboOutputLanguage.getText());
                        ConfigTranslateEngine.getInstance().setTranslatorEngine(m_comboEngineTranslate.getText());
                        
                        if(m_radioOperationAuto.getSelection()){
                            ConfigCommon.getInstance().setAutoMoveMouse(true);
                        }else{
                            ConfigCommon.getInstance().setAutoMoveMouse(false);
                        }
                        
                        if(m_radioModePlay.getSelection()){
                            ConfigCommon.getInstance().setAutoPlaySound(true);
                        }else{
                            ConfigCommon.getInstance().setAutoPlaySound(false);
                        }
                        
                        if(m_checkAutoTranslate.getSelection()){
                            ConfigCommon.getInstance().setAutoTranslate(true);
                        }else{
                            ConfigCommon.getInstance().setAutoTranslate(false);
                        }
                        updateContent();
                        NowMainWindow.getInstance().updateWidgetsContent();
                        m_btnApply.setEnabled(false);
                    }
                });
            }
        });
    
        //Set enable Apply button
        m_checkAutoTranslate.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_radioModeDisplay.addListener(SWT.Selection, new Listener() {
            
            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_radioModePlay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_radioOperationAuto.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_radioOperationPress.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_comboDisplay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_comboEngineTranslate.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_comboInputLanguage.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
        
        m_comboOutputLanguage.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                setEnableApplyButton();
            }
        });
    }
    
    private void setEnableApplyButton(){
        Display.getDefault().syncExec(new Runnable() {

            @Override
            public void run() {
                m_btnApply.setEnabled(true);
            }
        });
    }
            
    private void initializeDisplayTab(){
        String[] listDisplayLanguage = DisplayText.getInstance().getListDisplayLanguage();
        
        m_gridLayoutDisplay = new GridLayout();
        m_gridLayoutDisplay.numColumns = 2;
        m_gridLayoutDisplay.marginLeft = 5;
        m_gridLayoutDisplay.marginRight = 10;
        m_gridLayoutDisplay.marginTop = 20;
        
        m_compositeDisplay = new Composite(m_tabMain, SWT.NULL);
        m_compositeDisplay.setLayout(m_gridLayoutDisplay);
        m_tabItemDisplay.setControl(m_compositeDisplay);
        
        m_gridDataDisplayLeft = new GridData();
        m_gridDataDisplayLeft.horizontalAlignment = GridData.END;
        m_gridDataDisplayLeft.grabExcessVerticalSpace = false;
        m_gridDataDisplayLeft.widthHint = 140;
        //m_gridDataDisplayLeft.heightHint = 30;
        
        m_gridDataDisplayRight= new GridData();
        m_gridDataDisplayRight.horizontalAlignment = GridData.BEGINNING;
        m_gridDataDisplayRight.grabExcessHorizontalSpace = false;
        m_gridDataDisplayRight.widthHint = 200;
        //m_gridDataDisplayRight.heightHint = 30;
        
        m_labelDisplay = new Label(m_compositeDisplay, SWT.SINGLE);
        //m_labelDisplay.setText("Display Language:");
        m_labelDisplay.setLayoutData(m_gridDataDisplayLeft);
        
        m_comboDisplay = new Combo(m_compositeDisplay, SWT.READ_ONLY);
        m_comboDisplay.setItems(listDisplayLanguage);
        m_comboDisplay.select(UtilitiesCommon.getIndex(listDisplayLanguage, ConfigLanguage.getInstance().getDisplayLanguage()));
        m_comboDisplay.setLayoutData(m_gridDataDisplayRight);
    }
    
    private void initializeTranslateTab(){
        String[] listLanguageName = DefineLanguageName.getAllLanguageName();
        String[] listEngineName = DefineEngineName.getAllEngineName();
        
        m_gridLayoutTranslate = new GridLayout();
        m_gridLayoutTranslate.numColumns = 2;
        m_gridLayoutTranslate.marginLeft = 5;
        m_gridLayoutTranslate.marginRight = 10;
        m_gridLayoutTranslate.marginTop = 20;
        
        m_compositeTranslateMain = new Composite(m_tabMain, SWT.NULL);
        m_compositeTranslateMain.setLayout(m_gridLayoutTranslate);
        m_tabItemTranslate.setControl(m_compositeTranslateMain);
        
        m_gridDataTranslateLeft = new GridData();
        m_gridDataTranslateLeft.horizontalAlignment = GridData.END;
        m_gridDataTranslateLeft.grabExcessVerticalSpace = false;
        m_gridDataTranslateLeft.widthHint = 140;
        //m_gridDataTranslateLeft.heightHint = 30;
        
        m_gridDataTranslateRight= new GridData();
        m_gridDataTranslateRight.horizontalAlignment = GridData.BEGINNING;
        m_gridDataTranslateRight.grabExcessHorizontalSpace = false;
        m_gridDataTranslateRight.widthHint = 200;
        //m_gridDataTranslateRight.heightHint = 30;
        
        m_labelInputLanguage = new Label(m_compositeTranslateMain, SWT.SINGLE);
        //m_labelInputLanguage.setText("Input Language:");
        m_labelInputLanguage.setLayoutData(m_gridDataTranslateLeft);
        
        m_comboInputLanguage = new Combo(m_compositeTranslateMain, SWT.READ_ONLY);
        m_comboInputLanguage.setItems(listLanguageName);
        m_comboInputLanguage.select(UtilitiesCommon.getIndex(listLanguageName, 
                ConfigLanguage.getInstance().getInputLanguage()));
        m_comboInputLanguage.setLayoutData(m_gridDataTranslateRight);
        
        m_labelOutputLanguage = new Label(m_compositeTranslateMain, SWT.SINGLE);
        //m_labelOutputLanguage.setText("Output Language:");
        m_labelOutputLanguage.setLayoutData(m_gridDataTranslateLeft);
        
        m_comboOutputLanguage = new Combo(m_compositeTranslateMain, SWT.READ_ONLY);
        m_comboOutputLanguage.setItems(listLanguageName);
        m_comboOutputLanguage.select(UtilitiesCommon.getIndex(listLanguageName, 
                ConfigLanguage.getInstance().getOutputLanguage()));
        m_comboOutputLanguage.setLayoutData(m_gridDataTranslateRight);
                
        m_labelEngineTranslate = new Label(m_compositeTranslateMain, SWT.SINGLE);
        //m_labelEngineTranslate.setText("Translate Engine:");
        m_labelEngineTranslate.setLayoutData(m_gridDataTranslateLeft);
        
        m_comboEngineTranslate = new Combo(m_compositeTranslateMain, SWT.READ_ONLY);
        m_comboEngineTranslate.setItems(listEngineName);
        m_comboEngineTranslate.select(UtilitiesCommon.getIndex(listEngineName, ConfigTranslateEngine.getInstance().getTranslatorEngine()));
        m_comboEngineTranslate.setLayoutData(m_gridDataTranslateRight);
    }
    
    private void initializeGeneralTab(){
        m_gridLayoutGeneral = new GridLayout();
        m_gridLayoutGeneral.numColumns = 1;
        m_gridLayoutGeneral.marginLeft = 5;
        m_gridLayoutGeneral.marginRight = 10;
        
        m_compositeGeneralMain = new Composite(m_tabMain, SWT.NULL);
        m_tabItemGeneral.setControl(m_compositeGeneralMain);
        
        m_compositeGeneralMain.setLayout(m_gridLayoutGeneral);
        m_gridDataGeneral = new GridData();
        m_gridDataGeneral.horizontalAlignment = GridData.FILL;
        m_gridDataGeneral.grabExcessHorizontalSpace = true;
        m_gridDataGeneral.heightHint = 100;
        
        m_groupOperation = new Group(m_compositeGeneralMain, SWT.NULL);
        //m_groupOperation.setText("Operation");
        m_groupOperation.setLayoutData(m_gridDataGeneral);
        
        m_groupOutputMode = new Group(m_compositeGeneralMain, SWT.NULL);
        //m_groupOutputMode.setText("Output Mode");
        m_groupOutputMode.setLayoutData(m_gridDataGeneral);
                
        m_gridLayoutGeneralGroup = new GridLayout();
        m_gridLayoutGeneralGroup.numColumns = 1;
        m_gridLayoutGeneralGroup.marginLeft = 5;
        m_gridLayoutGeneralGroup.marginTop = 5;
        m_gridLayoutGeneralGroup.verticalSpacing = 15;
                
        m_groupOperation.setLayout(m_gridLayoutGeneralGroup);
        m_groupOutputMode.setLayout(m_gridLayoutGeneralGroup);
        
        m_gridDataGeneralGroup = new GridData();
        m_gridDataGeneralGroup.widthHint = 300;
        
        m_textOperation = new Text(m_groupOperation, SWT.WRAP);
        //m_textOperation.setText("Choise the way to play sound or display supported information.");
        m_textOperation.setLayoutData(m_gridDataGeneralGroup);
        
        m_radioOperationAuto = new Button(m_groupOperation, SWT.RADIO | SWT.WRAP);
        //m_radioOperationAuto.setText("Automatic when move mouse");
        m_radioOperationAuto.setSelection(ConfigCommon.getInstance().getAutoMoveMouse());
        m_radioOperationAuto.setLayoutData(m_gridDataGeneralGroup);
        
        m_radioOperationPress = new Button(m_groupOperation, SWT.RADIO);
        //m_radioOperationPress.setText("When press Ctrl keyboard");
        m_radioOperationPress.setSelection(!ConfigCommon.getInstance().getAutoMoveMouse());
        m_radioOperationPress.setLayoutData(m_gridDataGeneralGroup);
        
        m_radioModePlay = new Button(m_groupOutputMode, SWT.RADIO);
        //m_radioModePlay.setText("Play sound");
        m_radioModePlay.setSelection(ConfigCommon.getInstance().getAutoPlaySound());
        m_radioModePlay.setLayoutData(m_gridDataGeneralGroup);
        
        m_radioModeDisplay = new Button(m_groupOutputMode, SWT.RADIO);
        //m_radioModeDisplay.setText("Display information window");
        m_radioModeDisplay.setSelection(!ConfigCommon.getInstance().getAutoPlaySound());
        m_radioModeDisplay.setLayoutData(m_gridDataGeneralGroup);
        
        m_checkAutoTranslate = new Button(m_groupOutputMode, SWT.CHECK);
        //m_checkAutoTranslate.setText("Automatic translate to the output language");
        m_checkAutoTranslate.setSelection(ConfigCommon.getInstance().getAutoTranslate());
        m_checkAutoTranslate.setLayoutData(m_gridDataGeneralGroup);
    }
    
    private void initializeMainFrame(){
        m_gridLayoutMain = new GridLayout();
        m_gridLayoutMain.numColumns = 1;
        
        m_shell.setLayout(m_gridLayoutMain);
        
        m_gridDataMain = new GridData();
        m_gridDataMain.horizontalAlignment = GridData.FILL;
        m_gridDataMain.grabExcessHorizontalSpace = true;
        m_gridDataMain.heightHint = 370;
        
        m_tabMain = new TabFolder(m_shell, SWT.NORMAL);
        m_tabMain.setLayoutData(m_gridDataMain);
        
        m_gridDataMainButton = new GridData();
        m_gridDataMainButton.horizontalAlignment = GridData.END;
        
        m_compositeMain = new Composite(m_shell, SWT.NORMAL);
        m_compositeMain.setLayoutData(m_gridDataMainButton);
        
        m_gridLayoutButton = new GridLayout();
        m_gridLayoutButton.numColumns = 3;
                
        m_gridDataButton = new GridData();
        m_gridDataButton.horizontalAlignment = GridData.END;
        m_gridDataButton.heightHint = NowConst.NOW_BUTTON_HEIGHT;
        m_gridDataButton.widthHint = NowConst.NOW_BUTTON_WIDTH;
        
        m_compositeMain.setLayout(m_gridLayoutButton);
        
        m_btnOK = new Button(m_compositeMain, SWT.PUSH);
        m_btnOK.setLayoutData(m_gridDataButton);
        //m_btnOK.setText("OK");
        
        m_btnCancel = new Button(m_compositeMain, SWT.PUSH);
        m_btnCancel.setLayoutData(m_gridDataButton);
        //m_btnCancel.setText("Cancel");
        
        m_btnApply = new Button(m_compositeMain, SWT.PUSH);
        m_btnApply.setLayoutData(m_gridDataButton);
        //m_btnApply.setText("Apply");
        m_btnApply.setEnabled(false);
        
        m_tabItemGeneral = new TabItem(m_tabMain, SWT.NULL);
        //m_tabItemGeneral.setText("General");
        m_tabItemTranslate = new TabItem(m_tabMain, SWT.NULL);
        //m_tabItemTranslate.setText("Translate");
        m_tabItemDisplay = new TabItem(m_tabMain, SWT.NULL);
        //m_tabItemDisplay.setText("Display");
    }
    
    private void updateContent(){
        m_shell.setText(DisplayText.getInstance().getText(DefineDisplayCode.WINDOW_CONFIG_TITLE));
        
        m_btnOK.setText(DisplayText.getInstance().getText(DefineDisplayCode.BUTTON_OK));
        m_btnCancel.setText(DisplayText.getInstance().getText(DefineDisplayCode.BUTTON_CANCEL));
        m_btnApply.setText(DisplayText.getInstance().getText(DefineDisplayCode.BUTTON_APPLY));
        
        m_tabItemGeneral.setText(DisplayText.getInstance().getText(DefineDisplayCode.TAB_GENERAL));
        m_tabItemTranslate.setText(DisplayText.getInstance().getText(DefineDisplayCode.TAB_TRANSLATE));
        m_tabItemDisplay.setText(DisplayText.getInstance().getText(DefineDisplayCode.TAB_DISPLAY));
        
        m_checkAutoTranslate.setText(DisplayText.getInstance().getText(DefineDisplayCode.CHECKBOX_AUTO_TRANSLATE));
        
        m_radioModeDisplay.setText(DisplayText.getInstance().getText(DefineDisplayCode.RADIO_MODE_DISPLAY));
        m_radioModePlay.setText(DisplayText.getInstance().getText(DefineDisplayCode.RADIO_MODE_PLAY));
        m_radioOperationPress.setText(DisplayText.getInstance().getText(DefineDisplayCode.RADIO_OPERATION_PRESS));
        m_radioOperationAuto.setText(DisplayText.getInstance().getText(DefineDisplayCode.RADIO_OPERATION_AUTO));
        
        m_textOperation.setText(DisplayText.getInstance().getText(DefineDisplayCode.TEXT_OPERATION));
        
        m_groupOutputMode.setText(DisplayText.getInstance().getText(DefineDisplayCode.GROUP_OUTPUT_MODE));
        m_groupOperation.setText(DisplayText.getInstance().getText(DefineDisplayCode.GROUP_OPERATION));
        
        m_labelEngineTranslate.setText(DisplayText.getInstance().getText(DefineDisplayCode.LABEL_ENGINE_TRANSLATE));
        m_labelOutputLanguage.setText(DisplayText.getInstance().getText(DefineDisplayCode.LABEL_OUTPUT_LANGUAGE));
        m_labelInputLanguage.setText(DisplayText.getInstance().getText(DefineDisplayCode.LABEL_INPUT_LANGUAGE));
        m_labelDisplay.setText(DisplayText.getInstance().getText(DefineDisplayCode.LABEL_DISPLAY));
    }
    
    public static NowConfigurationWindow getInstance(){
        if(m_instance == null){
            m_instance = new NowConfigurationWindow();
        }
        return m_instance;
    }
    
    /**
     * Show config window
     * @param display Display contain config window
     */
    public void showWindow(Display display){        
        if(m_shell == null || m_shell.isDisposed()){
            m_shell = new Shell(display, SWT.DIALOG_TRIM);
            initializeWindow();
            //ImageData data = new ImageData(NowConst.FILE_IMAGE_SETTING_ICON);
            //Image image = new Image(Display.getDefault(), data);
            m_shell.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_SETTING_ICON)));
            setDisplayPointAtCenterScreen(display);
            //m_shell.pack();
            m_shell.open();
        }
    }
    
    /**
     * Close config window
     */
    public void closeWindow(){  
        if(m_shell != null && !m_shell.isDisposed()){
            m_shell.close();
        }
    }

    private static NowConfigurationWindow m_instance = null;
    private Shell m_shell = null;
    /**
     * for main widow
     */
    private TabFolder m_tabMain = null;
    private TabItem m_tabItemGeneral = null;
    private TabItem m_tabItemTranslate = null;
    private TabItem m_tabItemDisplay    = null;
    
    private Button m_btnOK = null;
    private Button m_btnCancel = null;
    private Button m_btnApply = null;
    
    private GridLayout m_gridLayoutMain = null;
    private GridData m_gridDataMain = null;
    
    private Composite m_compositeMain = null;
    private GridLayout m_gridLayoutButton = null;
    private GridData m_gridDataButton = null;
    private GridData m_gridDataMainButton = null;
    /**
     * for m_tabItemGeneral
     */
    private GridLayout m_gridLayoutGeneral = null;
    private GridData m_gridDataGeneral = null;
    private Composite m_compositeGeneralMain = null;
    
    private GridLayout m_gridLayoutGeneralGroup = null;
    private GridData m_gridDataGeneralGroup = null;
        
    private Group m_groupOperation = null;
    private Group m_groupOutputMode = null;
    private Button m_radioOperationAuto = null;
    private Button m_radioOperationPress = null;
    private Button m_radioModePlay = null;
    private Button m_radioModeDisplay = null;
    private Button m_checkAutoTranslate = null;
    
    private Text m_textOperation = null;
    /**
     * for m_tabItemTranslate
     */
    private GridLayout m_gridLayoutTranslate = null;
    private GridData m_gridDataTranslateLeft = null;
    private GridData m_gridDataTranslateRight = null;
    private Composite m_compositeTranslateMain = null;
    
    private Label m_labelInputLanguage = null;
    private Label m_labelOutputLanguage = null;
    private Label m_labelEngineTranslate = null;
    
    private Combo m_comboInputLanguage = null;
    private Combo m_comboOutputLanguage = null;
    private Combo m_comboEngineTranslate = null;
    /**
     * for m_tabItemDisplay
     */
    private GridLayout m_gridLayoutDisplay = null;
    private GridData m_gridDataDisplayLeft = null;
    private GridData m_gridDataDisplayRight = null;
    private Composite m_compositeDisplay = null;
    
    private Label m_labelDisplay = null;
    private Combo m_comboDisplay = null;
}
