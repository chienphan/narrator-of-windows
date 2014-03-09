/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.DisposeEvent;
import org.eclipse.swt.events.DisposeListener;
import org.eclipse.swt.events.ShellEvent;
import org.eclipse.swt.events.ShellListener;
import org.eclipse.swt.graphics.Cursor;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Monitor;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;

/**
 *
 * @author Administrator
 */
public class NowConfigurationWindow {
    private static NowConfigurationWindow m_instance = null;
    private Shell m_shell = null;
        
    private NowConfigurationWindow(){
    }
    
    private void setDisplayPointAtCenterScreen(Display display, Shell shell){
        Monitor primary = display.getPrimaryMonitor ();
        Rectangle bounds = primary.getBounds ();
        Rectangle rect = shell.getBounds ();
        int x = bounds.x + (bounds.width - rect.width) / 2;
        int y = bounds.y + (bounds.height - rect.height) / 2;
        shell.setLocation (x, y);
    }
    
    public static NowConfigurationWindow getInstance(){
        if(m_instance == null){
            m_instance = new NowConfigurationWindow();
        }
        return m_instance;
    }
    
    public void showConfigurationWindow(){
        
    }
    
    public void closeConfigurationWindow(){
        
    }
}