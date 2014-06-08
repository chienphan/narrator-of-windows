/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import now.lib.configuration.ConfigCommon;
import now.lib.constant.NowConst;
import now.lib.define.DefineDisplayCode;
import now.lib.display.DisplayText;
import now.lib.utilities.UtilitiesCommon;
import now.lib.utilities.UtilitiesDevice;
import now.lib.utilities.UtilitiesFileTXT;
import org.eclipse.swt.SWT;
import org.eclipse.swt.SWTError;
import org.eclipse.swt.browser.Browser;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.ImageData;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.CoolBar;
import org.eclipse.swt.widgets.CoolItem;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;

/**
 *
 * @author chien.phan
 */
public class NowMainWindow {
    private static NowMainWindow m_instance = null;
    private Shell m_shell = null;
    
    //Menu bar
    private Menu m_menuBar = null;
    private MenuItem m_menuButtonFile = null;
    private MenuItem m_menuButtonTools = null;
    private MenuItem m_menuButtonRun = null;
    private MenuItem m_menuButtonHelp = null;
    
    private Menu m_menuPopupFile = null;
    private MenuItem m_menuItemClose = null;
    private MenuItem m_menuItemExit = null;
    
    private Menu m_menuPopupTools = null;
    private MenuItem m_menuItemConfig = null;
    
    private Menu m_menuPopupRun = null;
    private MenuItem m_menuItemRun = null;
    
    private Menu m_menuPopupHelp = null;
    private MenuItem m_menuItemAbout = null;
    
    //Tool bar
    private CoolBar m_toolBar = null;
    
    /////////////////////////////////////////
    private Composite m_compositeCenter = null;
    private Composite m_compositeContent = null;
    private Tree m_treeData = null;
    
    private Browser m_browser = null;
        
    private RowLayout m_rowlayoutMain = null;
    private RowData m_rowdataMain = null;
    
    private GridLayout m_gridlayoutCenter = null;
    private GridData m_griddataTree = null;
    private GridData m_griddataContent = null;
    
    private RowData m_rowdataContent = null;
    ///////////////////////////////////
    private CoolItem m_toolbarItem = null;
    private Composite m_compositeToolbar = null;
    private Combo m_comboSpeed = null;
    
    private Button m_buttonPlay = null;
    private Button m_buttonConfig = null;
    
    private NowMainWindow(){
        
    }
    
    private void initWidgets(){   
        m_rowlayoutMain = new RowLayout();
        m_rowdataMain = new RowData();
        m_rowdataMain.height = 27;
        m_rowdataMain.width = 635;
        
        m_shell.setLayout(m_rowlayoutMain);
        
        //Create menu bar
        m_menuBar = new Menu (m_shell, SWT.BAR);
	m_shell.setMenuBar (m_menuBar);
        
        //Create menu button File
        m_menuButtonFile = new MenuItem (m_menuBar, SWT.CASCADE);
	m_menuButtonTools = new MenuItem (m_menuBar, SWT.CASCADE);
        m_menuButtonRun = new MenuItem (m_menuBar, SWT.CASCADE);
        m_menuButtonHelp = new MenuItem (m_menuBar, SWT.CASCADE);
                
        //Create popup menu FILE
        m_menuPopupFile = new Menu (m_shell, SWT.DROP_DOWN);
	m_menuButtonFile.setMenu (m_menuPopupFile);
        
        m_menuItemClose = new MenuItem(m_menuPopupFile, SWT.PUSH);
        m_menuItemClose.setAccelerator (SWT.MOD1 + 'X');
        m_menuItemClose.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_CLOSE_ICON)));
        m_menuItemExit = new MenuItem(m_menuPopupFile, SWT.PUSH);
        m_menuItemExit.setAccelerator (SWT.MOD1 + 'Q');
        m_menuItemExit.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_SHUTDOWN_ICON)));
        
        //Create popup menu TOOLS
        m_menuPopupTools = new Menu(m_shell, SWT.DROP_DOWN);
        m_menuButtonTools.setMenu (m_menuPopupTools);
        
        m_menuItemConfig = new MenuItem(m_menuPopupTools, SWT.PUSH);
        m_menuItemConfig.setAccelerator (SWT.MOD1 + 'G');
        m_menuItemConfig.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_SETTING_ICON)));
        
        //Create popup menu TOOLS
        m_menuPopupRun = new Menu(m_shell, SWT.DROP_DOWN);
        m_menuButtonRun.setMenu (m_menuPopupRun);
        
        m_menuItemRun = new MenuItem(m_menuPopupRun, SWT.PUSH);
        m_menuItemRun.setAccelerator (SWT.F5);
        m_menuItemRun.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_PLAY_ICON)));
        
        //Create popup menu HELP
        m_menuPopupHelp = new Menu(m_shell, SWT.DROP_DOWN);
        m_menuButtonHelp.setMenu (m_menuPopupHelp);
        
        m_menuItemAbout = new MenuItem(m_menuPopupHelp, SWT.PUSH);
        
        //Tool Bar
        m_toolBar = new CoolBar (m_shell, SWT.NONE);
        
        m_toolbarItem = new CoolItem(m_toolBar, SWT.DROP_DOWN);

        m_compositeToolbar = new Composite(m_toolBar, SWT.NONE);
        //RowLayout rowlayout = new RowLayout();
        //RowData rowData = new RowData();
        m_compositeToolbar.setLayout(new RowLayout());
        RowData rowdata = new RowData();
        rowdata.width = 100;
        m_compositeToolbar.setLayoutData(rowdata);
        
        m_comboSpeed = new Combo(m_compositeToolbar, SWT.DROP_DOWN | SWT.READ_ONLY | SWT.FLAT | SWT.BORDER);
        //m_comboSpeed.setItems (new String [] {"Nhanh", "Vừa phải", "Chậm"});
        //m_comboSpeed.select(Integer.parseInt(ConfigCommon.getInstance().getSpeed()) - 1);
             
        m_buttonPlay = new Button(m_compositeToolbar, SWT.PUSH | SWT.NONE | SWT.FILL);
        m_buttonPlay.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_PLAY_ICON)));
                
        m_buttonConfig = new Button(m_compositeToolbar, SWT.PUSH | SWT.NONE);
        m_buttonConfig.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_SETTING_ICON)));
                        
        m_toolbarItem.setControl(m_compositeToolbar);
        
        Control control = m_toolbarItem.getControl();
        Point pt = control.computeSize(SWT.DEFAULT, SWT.DEFAULT);
        pt = m_toolbarItem.computeSize(650, pt.y);
        m_toolbarItem.setSize(pt);
        
        m_toolBar.pack();
        
        //Itit center area
        m_gridlayoutCenter = new GridLayout();
        m_gridlayoutCenter.numColumns = 2;
        
        m_griddataTree = new GridData();
        m_griddataTree.heightHint = 300;
        m_griddataTree.widthHint = 180;
        
        m_compositeCenter = new Composite(m_shell, SWT.NORMAL);
        m_compositeCenter.setLayout(m_gridlayoutCenter);
        
        m_treeData = new Tree (m_compositeCenter, SWT.BORDER);
        m_treeData.setLayoutData(m_griddataTree);
	initTreeData();
        
        m_griddataContent = new GridData();
        m_griddataContent.heightHint = 318;
        m_griddataContent.widthHint = 420;
        
        m_compositeContent = new Composite(m_compositeCenter, SWT.BORDER);
        m_compositeContent.setLayout(new RowLayout());
        m_compositeContent.setLayoutData(m_griddataContent);
        
        m_rowdataContent = new RowData();
        m_rowdataContent.width = 414;
        m_rowdataContent.height = 350;
        
        
        try {
            m_browser = new Browser(m_compositeContent, SWT.NONE);
        } catch (SWTError e) {
            System.out.println("Could not instantiate Browser: " + e.getMessage());
            //display.dispose();
            return;
        }
        m_browser.setLayoutData(m_rowdataContent);
        m_browser.setText(NowConst.DEFAULT_STRING);
        
        //m_buttonPlay = new Button(m_compositeContent, SWT.PUSH);
        //m_buttonPlay.setLayoutData(m_rowdataContent);
    }
    
    public void updateWidgetsContent(){
        m_shell.setText(DisplayText.getInstance().getText(DefineDisplayCode.WINDOW_MAIN_TITLE));
        //m_buttonPlay.setText("Play");
        
        m_menuButtonFile.setText (DisplayText.getInstance().getText(DefineDisplayCode.MENU_FILE));
        m_menuItemClose.setText (DisplayText.getInstance().getText(DefineDisplayCode.MENU_CLOSE));
	m_menuItemExit.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_EXIT));
        
        m_menuButtonTools.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_TOOL));
        m_menuItemConfig.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_CONFIG));
        
        m_menuButtonRun.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_RUN));
        m_menuItemRun.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_RUN_LESSON));
        
        m_menuButtonHelp.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_HELP));
        m_menuItemAbout.setText(DisplayText.getInstance().getText(DefineDisplayCode.MENU_ABOUT));
        
        m_comboSpeed.removeAll();
        m_comboSpeed.setItems (new String [] {
            DisplayText.getInstance().getText(DefineDisplayCode.SPEED_FAST), 
            DisplayText.getInstance().getText(DefineDisplayCode.SPEED_NORMAL), 
            DisplayText.getInstance().getText(DefineDisplayCode.SPEED_SLOW)});
        m_comboSpeed.select(Integer.parseInt(ConfigCommon.getInstance().getSpeed()) - 1);
    }
    
    private void initListener(){
        m_buttonPlay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                runTest();
            }
        });
        
        m_buttonConfig.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                NowConfigurationWindow.getInstance().showWindow(Display.getDefault());
            }
        });
        
        m_comboSpeed.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                ConfigCommon.getInstance().setSpeed(String.valueOf(m_comboSpeed.getSelectionIndex() + 1));
            }
        });
        
        m_menuItemClose.addListener (SWT.Selection, new Listener () {
            @Override
            public void handleEvent (Event e) {
                System.out.println ("Close");
                m_shell.dispose();
            }
	});
        
        m_menuItemExit.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                System.out.println ("Exit");
                System.exit(0);
            }
        });
        
        m_menuItemConfig.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                System.out.println ("Config");
                //Display currentDisplay = 
                NowConfigurationWindow.getInstance().showWindow(Display.getDefault());
            }
        });
        
        m_menuItemRun.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                System.out.println ("Run");
                runTest();
            }
        });
        
        m_menuItemAbout.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                System.out.println ("About");
                //TODO: About window show here!!!!!!!!
                MessageBox messageBox = new MessageBox(m_shell, SWT.ICON_INFORMATION | SWT.OK );
        
                messageBox.setText(DisplayText.getInstance().getText(DefineDisplayCode.DIALOG_ABOUT));
                UtilitiesFileTXT aboutFile = new UtilitiesFileTXT(NowConst.FILE_ABOUT);
                String info = aboutFile.getContent();
                
                messageBox.setMessage(info);
                messageBox.open();
            }
        });
        
        m_treeData.addSelectionListener(new SelectionListener() {

            @Override
            public void widgetSelected(SelectionEvent se) {
                if(m_treeData.getSelectionCount() == 1){
                    TreeItem selectedItem = m_treeData.getSelection()[0];
                    String data = "." + (String)selectedItem.getData();
                    if(!data.equals(".")){
                        final String content = "<b>Bài tập " + UtilitiesCommon.getLessonName(data) +"</b>"
                                + "<br/><code>" +  UtilitiesCommon.getLessonDescription(data) + "</code>";
                        
                        Display.getDefault().syncExec(new Runnable() {

                            @Override
                            public void run() {
                                m_browser.setText(content);
                            }
                        });
                    }
                    else
                    {
                        Display.getDefault().syncExec(new Runnable() {

                            @Override
                            public void run() {
                                m_browser.setText(NowConst.DEFAULT_STRING);
                            }
                        });
                    }
                }
            }

            @Override
            public void widgetDefaultSelected(SelectionEvent se) {
                
            }
        });
    }
    
    private void initTreeData(){
        ArrayList<String> arrayTitleFolder = UtilitiesDevice.getAllDirectoryName(new File(".\\" + NowConst.DIRECTORY_DATA));
        for (String folder : arrayTitleFolder) {
            TreeItem iItem = new TreeItem(m_treeData, 0);
            iItem.setText(folder);
            iItem.setData("");
            //ImageData dataFolder = new ImageData(NowConst.FILE_IMAGE_FOLDER_ICON);
            //Image imageFolder = new Image(Display.getDefault(), dataFolder);
            iItem.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_FOLDER_ICON)));
            
            ArrayList<String> arrayTitleLesson = UtilitiesDevice.getAllFileName(new File(".\\" + NowConst.DIRECTORY_DATA + "\\" + folder));
            for (String lesson : arrayTitleLesson) {
                String path = "\\" + NowConst.DIRECTORY_DATA + "\\" + folder + "\\" + lesson;
                if (path.isEmpty()) {
                    break;
                }
                String lessonName = UtilitiesCommon.getLessonName("." + path);
                if (lessonName.isEmpty()) {
                    break;
                }
                TreeItem kItem = new TreeItem(iItem, 0);
                kItem.setText(lessonName);
                kItem.setData(path);
                //ImageData data = new ImageData(NowConst.FILE_IMAGE_PLAY_ICON);
                //Image image = new Image(Display.getDefault(), data);
                kItem.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_PLAY_ICON)));
            }
        }
    }
    
    private void runTest(){
        String path = "";
        TreeItem[] items = m_treeData.getSelection();
        if (items.length == 1) {
            path = (String)items[0].getData();
            //System.out.println(path);
        }

        if(!path.isEmpty()){
            m_shell.setMinimized(true);

            try {
                new ProcessBuilder( NowConst.DIRECTORY_EXECUTABLE, path , ConfigCommon.getInstance().getSpeed()).start();
            } catch (IOException ex) {
                Logger.getLogger(NowMain.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public static NowMainWindow getInstance(){
        if (m_instance == null) {
            m_instance = new NowMainWindow();
        }
        return m_instance;
    }
            
    public void showWindow(Display display){        
        if(m_shell == null || m_shell.isDisposed()){
            m_shell = new Shell(display, SWT.CLOSE | SWT.TITLE | SWT.MIN );
            m_shell.setLayout(new FillLayout());
            m_shell.setSize(650, 430);
            //ImageData data = new ImageData(NowConst.FILE_IMAGE_TRAY_ICON);
            //Image image = new Image(Display.getDefault(), data);
            m_shell.setImage(new Image(Display.getDefault(), new ImageData(NowConst.FILE_IMAGE_TRAY_ICON)));
            initWidgets();
            updateWidgetsContent();
            initListener();
            m_shell.open();
        }
        else
        {
            m_shell.setActive();
        }
    }
}
