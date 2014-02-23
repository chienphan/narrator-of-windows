/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import java.util.logging.Level;
import java.util.logging.Logger;
import now.lib.configuration.ConfigDefine;
import now.lib.define.DefineDisplayCode;
import now.lib.display.DisplayText;
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

/**
 *
 * @author Chien.Phan
 */
public class NowSystemTray {
    private static NowSystemTray m_instance = null;
    private Display display = null;
    private Shell configShell = null;
    private NowSystemTray(){
        
    }
    
    public static NowSystemTray getInstance(){
        if(m_instance == null){
            m_instance = new NowSystemTray();
        }
        return m_instance;
    }
    
    public void bbb(){};
    
    public void showSystemTray(){
        //Create display
        display = new Display();
	Shell shell = new Shell(display);
        
        ImageData imageData = new ImageData(ConfigDefine.FILE_IMAGE_TRAY_ICON);
	Image image = new Image(display, imageData);
        
        //Create system tray icon
        final Tray tray = display.getSystemTray();
	if (tray == null) {
            System.out.println("The system tray is not available");
        } else {
            final TrayItem itemTray = new TrayItem(tray, SWT.NONE);
            //Set tooltip for tray icon
            itemTray.setToolTipText("Click to show menu");
	            
            //Build popup menu
            final Menu popupMenu = new Menu(shell, SWT.POP_UP);
                 
            MenuItem menuShowConfigWindow = new MenuItem(popupMenu, SWT.PUSH);
            menuShowConfigWindow.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_CONFIGURATION));
            menuShowConfigWindow.addListener(SWT.Selection, new Listener() {

                @Override
                public void handleEvent(Event event) {
                    if(configShell == null || configShell.isDisposed()){
                        configShell = new Shell(display, SWT.DIALOG_TRIM);
                        configShell.setSize(500, 250);
                        configShell.open();
                        System.out.println("open!!!");
                    }
                }
            });
            
            popupMenu.setDefaultItem(menuShowConfigWindow);
            
            MenuItem separator = new MenuItem(popupMenu, SWT.SEPARATOR);
            
            MenuItem menuClose = new MenuItem(popupMenu, SWT.PUSH);
            menuClose.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_EXIT));
            menuClose.addListener(SWT.Selection, new Listener() {

                @Override
                public void handleEvent(Event event) {
                    itemTray.dispose();
                    System.exit(0);
                }
            });
            
            itemTray.addListener(SWT.MenuDetect, new Listener() {
                public void handleEvent(Event event) {
                    popupMenu.setVisible(true);
                }
            });
            
            itemTray.addListener(SWT.Selection, new Listener() {

                @Override
                public void handleEvent(Event event) {
                    popupMenu.setVisible(true);
                }
            });
            
            itemTray.setImage(image);
        }
        
        while (!shell.isDisposed()) {
          if (!display.readAndDispatch())
            display.sleep();
        }
        image.dispose();
        display.dispose();
    }
}
