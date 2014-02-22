/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import now.lib.define.DefineDisplayCode;
import now.lib.display.DisplayText;
import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.widgets.*;

/**
 *
 * @author Administrator
 */
public class NowMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
       // System.out.print(DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_CONFIGURATION));
        // TODO code application logic here
        Display display = new Display();
	    Shell shell = new Shell(display);
	    Image image = new Image(display, 16, 16);
	    final Tray tray = display.getSystemTray();
	    if (tray == null) {
	      System.out.println("The system tray is not available");
	    } else {
	      final TrayItem item = new TrayItem(tray, SWT.NONE);
	      item.setToolTipText("SWT TrayItem");
	      item.addListener(SWT.Show, new Listener() {
	        public void handleEvent(Event event) {
	          System.out.println("show");
	        }
	      });
	      item.addListener(SWT.Hide, new Listener() {
	        public void handleEvent(Event event) {
	          System.out.println("hide");
	        }
	      });
	      item.addListener(SWT.Selection, new Listener() {
	        public void handleEvent(Event event) {
	          System.out.println("selection");
	        }
	      });
	      item.addListener(SWT.DefaultSelection, new Listener() {
	        public void handleEvent(Event event) {
	          System.out.println("default selection");
	        }
	      });
	      final Menu menu = new Menu(shell, SWT.POP_UP);
	      for (int i = 0; i < 8; i++) {
	        MenuItem mi = new MenuItem(menu, SWT.PUSH);
	        mi.setText( DisplayText.getInstance().getText(DefineDisplayCode.SYSTEM_TRAY_CONFIGURATION) + i);
	        
                mi.addListener(SWT.Selection, new Listener() {
	          public void handleEvent(Event event) {
	            System.out.println("selection ==" + event.widget);
                    
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(NowFrameSetting.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NowFrameSetting.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NowFrameSetting.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NowFrameSetting.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new NowFrameSetting().setVisible(true);
            }
        });
                    
                    
	          }
	        });
	        if (i == 0)
	          menu.setDefaultItem(mi);
	      }
	      item.addListener(SWT.MenuDetect, new Listener() {
	        public void handleEvent(Event event) {
	          menu.setVisible(true);
	        }
	      });
	      item.setImage(image);
	    }
	  //  shell.setBounds(50, 50, 300, 200);
//	    shell.open();
	    while (!shell.isDisposed()) {
	      if (!display.readAndDispatch())
	        display.sleep();
	    }
	    image.dispose();
	    display.dispose();
   }
    
}
