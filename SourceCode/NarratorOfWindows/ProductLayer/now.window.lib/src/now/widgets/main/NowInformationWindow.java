/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import now.lib.jni.JNICaller;
import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.jnativehook.GlobalScreen;
import org.jnativehook.mouse.NativeMouseEvent;
import org.jnativehook.mouse.NativeMouseInputListener;

/**
 *
 * @author gobom
 */
public class NowInformationWindow implements NativeMouseInputListener {
    private static NowInformationWindow m_instance = null;
    private Shell shell = null;
    private double distance = 0.0;
    private Rectangle windowRectangle = null;
    private Point windowPoint = null;
    
    private NowInformationWindow(){
        
    }
    
    private void initWindow(){
        Point currentMousePoint = shell.getDisplay().getCursorLocation();
        shell.setSize(500, 250);
        shell.setLayout(new FillLayout());
        shell.setLocation(new Point(currentMousePoint.x + 20, currentMousePoint.y + 20));
        
        Text text = new Text(shell, SWT.MULTI | SWT.WRAP);
        String signature = JNICaller.getInstance().getControlSignatureUnderMouse();
        String informationt = "N/A";
        //Do not need check the control is changed or not. 
        //If the control is changed, the signature will not null.
        if(!signature.isEmpty())
        {
            informationt = JNICaller.getInstance().getUIInformation(signature);
            text.setText(informationt);
        }
    }
    
    private void initDistance(){
        windowPoint = new Point(shell.getLocation().x + shell.getSize().x / 2,
                                        shell.getLocation().y + shell.getSize().y / 2);
        System.out.println("Point of windows: " + windowPoint.x + ", " + windowPoint.y);
        Point mousePoint = shell.getDisplay().getCursorLocation();
             
        System.out.println("Point of mouse: " + mousePoint.x + ", " + mousePoint.y);
        
        distance = getDistance(windowPoint, mousePoint);
        System.out.println("Distance: " + distance);
    }
    
    private double getDistance(Point pointA, Point pointB){
        return Math.sqrt((pointA.x - pointB.x)*(pointA.x - pointB.x) 
                            + (pointA.y - pointB.y)*(pointA.y - pointB.y));
    }
    
    private void initMouseMoveListener(){
            GlobalScreen.getInstance().addNativeMouseListener(NowInformationWindow.getInstance());
            GlobalScreen.getInstance().addNativeMouseMotionListener(NowInformationWindow.getInstance());
    }
    
    public static NowInformationWindow getInstance(){
        if(m_instance == null){
            m_instance = new NowInformationWindow();
        }
        return m_instance;
    }
    
    public void showWindow(Display display){
        if(shell == null || shell.isDisposed()){
            shell = new Shell(display, SWT.BORDER_DASH | SWT.ON_TOP);
            
            initWindow();
            shell.open();
            initDistance();
            windowRectangle = new Rectangle(shell.getLocation().x, shell.getLocation().y, 
                                                shell.getSize().x, shell.getSize().y);
            initMouseMoveListener();
            System.out.println("open!!!");
        }
    }

    @Override
    public void nativeMouseMoved(NativeMouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        
        if(!shell.isDisposed()){
            Point mousePoint = new Point(e.getX(), e.getY());
            System.out.println("Point of mouse: " + mousePoint.x + ", " + mousePoint.y);
            if(!windowRectangle.contains(mousePoint) && (getDistance(windowPoint, mousePoint) > distance)){
                Display.getDefault().asyncExec(new Runnable() {
                    @Override
                    public void run() {
                        shell.dispose();
                    }
                });
            }
        }
    }

    @Override
    public void nativeMouseDragged(NativeMouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void nativeMouseClicked(NativeMouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void nativeMousePressed(NativeMouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void nativeMouseReleased(NativeMouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
