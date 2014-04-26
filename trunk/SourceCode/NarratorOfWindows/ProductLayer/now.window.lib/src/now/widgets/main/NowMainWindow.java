/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import now.lib.define.DefineDisplayCode;
import now.lib.display.DisplayText;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
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
    private Tree m_tree = null;
    private Button m_buttonPlay = null;
    private Composite m_composite = null;
    
    private NowMainWindow(){
        
    }
    
    private void initWindow(){   
        m_shell.setText(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_MAIN_WINDOW));
        initTable();
        initButtonPlay();
    }
    
    private void initButtonPlay(){
        m_composite = new Composite(m_shell, SWT.NORMAL);
        m_composite.setLayout(new RowLayout());
        
        m_buttonPlay = new Button(m_composite, SWT.PUSH);
        m_buttonPlay.setText("Play");
        
        m_buttonPlay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                
                m_shell.setMinimized(true);
                
                String exePath = "f:\\My_Data\\narrator-of-windows\\SourceCode\\NarratorOfWindows\\bin\\Debug_32\\now.play.exe";
                String arg = "\\data\\lesson001.dat";
                try {
                    Process process = new ProcessBuilder( exePath, arg ).start();
                } catch (IOException ex) {
                    Logger.getLogger(NowMain.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
    }
    
    private void initTable(){
        m_shell.setLayout(new FillLayout());
	m_tree = new Tree (m_shell, SWT.BORDER);
	for (int i=0; i<4; i++) {
            TreeItem iItem = new TreeItem (m_tree, 0);
            iItem.setText ("TreeItem (0) -" + i);
            for (int j=0; j<4; j++) {
                TreeItem jItem = new TreeItem (iItem, 0);
                jItem.setText ("TreeItem (1) -" + j);
                for (int k=0; k<4; k++) {
                    TreeItem kItem = new TreeItem (jItem, 0);
                    kItem.setText ("TreeItem (2) -" + k);
                    for (int l=0; l<4; l++) {
                        TreeItem lItem = new TreeItem (kItem, 0);
                        lItem.setText ("TreeItem (3) -" + l);
                    }
                }
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
            initWindow();
            m_shell.setSize(650, 400);
            m_shell.open();
        }
        else
        {
            m_shell.setActive();
        }
    }
}
