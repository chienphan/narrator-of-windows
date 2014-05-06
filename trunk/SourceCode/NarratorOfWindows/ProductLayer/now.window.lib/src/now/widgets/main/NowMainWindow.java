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
import now.lib.configuration.ConfigDefine;
import now.lib.define.DefineDisplayCode;
import now.lib.display.DisplayText;
import now.lib.utilities.UtilitiesCommon;
import now.lib.utilities.UtilitiesDevice;
import org.eclipse.swt.SWT;
import org.eclipse.swt.SWTError;
import org.eclipse.swt.browser.Browser;
import org.eclipse.swt.events.MenuEvent;
import org.eclipse.swt.events.MenuListener;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.graphics.Device;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.ImageData;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.ToolItem;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;

/**
 *
 * @author chien.phan
 */
public class NowMainWindow {
    private static NowMainWindow m_instance = null;
    private Shell m_shell = null;
    
    private ToolBar m_toolBar = null;
    private ToolItem m_itemFile = null;
    private ToolItem m_itemHelp = null;
    
    private Composite m_compositeCenter = null;
    private Composite m_compositeContent = null;
    private Tree m_treeData = null;
    private Button m_buttonPlay = null;
    private Browser m_browser = null;
    
    private Menu m_menuFile = null;
    private MenuItem m_menuItemClose = null;
    
    private Menu m_menuHelp = null;
    private MenuItem m_menuItemHelp = null;
    private MenuItem m_menuItemAbout = null;
    
    private RowLayout m_rowlayoutMain = null;
    private RowData m_rowdataMain = null;
    
    private GridLayout m_gridlayoutCenter = null;
    private GridData m_griddataTree = null;
    private GridData m_griddataContent = null;
    
    private RowData m_rowdataContent = null;
    
    private NowMainWindow(){
        
    }
    
    private void initWidgets(){   
        m_rowlayoutMain = new RowLayout();
        m_rowdataMain = new RowData();
        m_rowdataMain.height = 27;
        m_rowdataMain.width = 635;
        
        m_shell.setLayout(m_rowlayoutMain);
        
        //Init toolBar
        m_toolBar = new ToolBar (m_shell,SWT.BORDER | SWT.FLAT | SWT.WRAP);
	Rectangle clientArea = m_shell.getClientArea();
	m_toolBar.setLocation(clientArea.x, clientArea.y);
        m_toolBar.setLayoutData(m_rowdataMain);
        
        //Init ToolBar Item
        m_itemFile = new ToolItem (m_toolBar, SWT.CHECK);
        m_itemHelp = new ToolItem (m_toolBar, SWT.CHECK);
        
        //Menu File
        m_menuFile = new Menu (m_shell, SWT.POP_UP);
	m_menuItemClose = new MenuItem(m_menuFile, SWT.PUSH);
        
        //Menu Help
        m_menuHelp = new Menu(m_shell, SWT.POP_UP);
        m_menuItemHelp = new MenuItem(m_menuHelp, SWT.PUSH);
        m_menuItemAbout = new MenuItem(m_menuHelp, SWT.PUSH);
        
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
        m_rowdataContent.height = 250;
        
        
        try {
            m_browser = new Browser(m_compositeContent, SWT.NONE);
        } catch (SWTError e) {
            System.out.println("Could not instantiate Browser: " + e.getMessage());
            //display.dispose();
            return;
        }
        m_browser.setLayoutData(m_rowdataContent);
        m_browser.setText(ConfigDefine.DEFAULT_STRING);
        
        m_buttonPlay = new Button(m_compositeContent, SWT.PUSH);
        //m_buttonPlay.setLayoutData(m_rowdataContent);
    }
    
    private void updateWidgetsContent(){
        m_shell.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_MAIN_WINDOW));
        m_itemFile.setText("File");
        m_itemHelp.setText("Help");
        m_buttonPlay.setText("Play");
        
        m_menuItemClose.setText("Close");
        m_menuItemHelp.setText("Help");
        m_menuItemAbout.setText("About");
    }
    
    private void initListener(){
        m_buttonPlay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                String path = "";
                TreeItem[] items = m_treeData.getSelection();
                if (items.length == 1) {
                    path = (String)items[0].getData();
                    //System.out.println(path);
                }
                
                if(!path.isEmpty()){
                    m_shell.setMinimized(true);
                
                    try {
                        Process process = new ProcessBuilder( ConfigDefine.DIRECTORY_EXECUTABLE, path ).start();
                    } catch (IOException ex) {
                        Logger.getLogger(NowMain.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        });
    
        m_itemFile.addListener (SWT.Selection, new Listener () {
            @Override
            public void handleEvent (Event event) {
                System.out.println("Selection item1");
                Rectangle rect = m_itemFile.getBounds ();
                Point pt = new Point (rect.x, rect.y + rect.height);
                pt = m_toolBar.toDisplay (pt);
                m_menuFile.setLocation (pt.x, pt.y);
                m_menuFile.setVisible (true);
            }
	});
        
        m_itemHelp.addListener (SWT.Selection, new Listener () {
            @Override
            public void handleEvent (Event event) {
                System.out.println("Selection item2");
                Rectangle rect = m_itemHelp.getBounds ();
                Point pt = new Point (rect.x, rect.y + rect.height);
                pt = m_toolBar.toDisplay (pt);
                m_menuHelp.setLocation (pt.x, pt.y);
                m_menuHelp.setVisible (true);
            }
	});
        
        m_menuFile.addMenuListener(new MenuListener() {

            @Override
            public void menuHidden(MenuEvent me) {
                if (m_itemFile.getSelection()) {
                    m_itemFile.setSelection(false);
                }
            }

            @Override
            public void menuShown(MenuEvent me) {
                
            }
        });
        
        m_menuHelp.addMenuListener(new MenuListener() {

            @Override
            public void menuHidden(MenuEvent me) {
                if (m_itemHelp.getSelection()) {
                    m_itemHelp.setSelection(false);
                }
            }

            @Override
            public void menuShown(MenuEvent me) {
                
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
                                m_browser.setText(ConfigDefine.DEFAULT_STRING);
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
        ArrayList<String> arrayTitleFolder = UtilitiesDevice.getAllDirectoryName(new File(".\\" + ConfigDefine.DIRECTORY_DATA));
        for (String folder : arrayTitleFolder) {
            TreeItem iItem = new TreeItem(m_treeData, 0);
            iItem.setText(folder);
            iItem.setData("");
            ImageData dataFolder = new ImageData("resource\\folder-icon.png");
            Image imageFolder = new Image(Display.getDefault(), dataFolder);
            iItem.setImage(imageFolder);
            
            ArrayList<String> arrayTitleLesson = UtilitiesDevice.getAllFileName(new File(".\\" + ConfigDefine.DIRECTORY_DATA + "\\" + folder));
            for (String lesson : arrayTitleLesson) {
                String path = "\\" + ConfigDefine.DIRECTORY_DATA + "\\" + folder + "\\" + lesson;
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
                ImageData data = new ImageData("resource\\play-icon.png");
                Image image = new Image(Display.getDefault(), data);
                kItem.setImage(image);
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
            m_shell.setSize(650, 400);
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
