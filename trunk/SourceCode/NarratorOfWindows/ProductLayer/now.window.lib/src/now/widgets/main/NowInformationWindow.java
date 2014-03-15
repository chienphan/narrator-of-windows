/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

import now.lib.configuration.ConfigLanguage;
import now.lib.configuration.ConfigTranslateEngine;
import now.lib.constant.NowConst;
import now.lib.define.DefineLanguageName;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.StyledText;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;
import org.jnativehook.GlobalScreen;
import org.jnativehook.mouse.NativeMouseEvent;
import org.jnativehook.mouse.NativeMouseInputListener;

/**
 *
 * @author gobom
 */
public class NowInformationWindow implements NativeMouseInputListener {
    private static NowInformationWindow m_instance = null;
    private String information = NowConst.NOW_EMPTY_STRING;
    private Shell shell = null;
    private double distance = 0.0;
    private Rectangle windowRectangle = null;
    private Point windowPoint = null;
    
    private NowInformationWindow(){
        ConfigTranslateEngine.getInstance().setTranslatorEngine(now.lib.define.DefineEngineName.TRANSLATOR_ENGINE_GOOGLE);
		ConfigLanguage.getInstance().setInputLanguage(DefineLanguageName.ENGLISH);
		ConfigLanguage.getInstance().setOutputLanguage(DefineLanguageName.VIETNAMESE);
    }
    
    private void initWindow(){
        Point currentMousePoint = shell.getDisplay().getCursorLocation();
        shell.setSize(500, 150);
        
        //Create grid layout
        GridLayout gridLayout = new GridLayout();
        gridLayout.numColumns = 1;
        
        GridData gridData = new GridData();
        gridData.horizontalAlignment = GridData.FILL;
        gridData.grabExcessHorizontalSpace = true;
        gridData.widthHint = 450;
        gridData.heightHint = 100;
        
        shell.setLayout(gridLayout);
        shell.setLocation(new Point(currentMousePoint.x + 20, currentMousePoint.y + 20));
        
        final StyledText text = new StyledText (shell, SWT.WRAP);
        text.setLayoutData(gridData);
        //text.setText("Do not need check the control is changed or not.");
        text.setSize(440, 50);
        
        final Composite composite = new Composite(shell, SWT.NONE);
        composite.setLayoutData(gridData);
        
        RowLayout rowLayout = new RowLayout();
        rowLayout.pack = false;
        composite.setLayout(rowLayout);
        
        text.setText(information);
         
        Button btnTranslate = new Button(composite, SWT.PUSH);
        btnTranslate.setText("Translate");
        btnTranslate.setSize(75, 24);
        
        btnTranslate.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                String strTemp = text.getText();
                String strOk = now.lib.translator.Translator.getInstance().translateAutoDetectInput(strTemp);
                text.setText(strOk);
            }
        });
        
        Button btnPlay = new Button(composite, SWT.PUSH);
        btnPlay.setText("Play");
        btnPlay.setSize(75, 24);
        
        btnPlay.addListener(SWT.Selection, new Listener() {

            @Override
            public void handleEvent(Event event) {
                String strTemp = text.getText();
                
                now.lib.translator.Audio.getInstance().play(strTemp);
                System.out.println(strTemp);
            }
        });
    }
        
    private void initDistance(){
        windowPoint = new Point(shell.getLocation().x + shell.getSize().x / 2,
                                        shell.getLocation().y + shell.getSize().y / 2);
        Point mousePoint = shell.getDisplay().getCursorLocation();
        distance = getDistance(windowPoint, mousePoint);
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
    
    public void showWindow(Display display, String information){
        this.information = information;
        
        if(shell != null ){
            if(!shell.isDisposed()){
                shell.dispose();
            }
        }
        
        shell = new Shell(display, SWT.BORDER_DASH | SWT.ON_TOP);
        initWindow();
        shell.open();
        initDistance();
        windowRectangle = new Rectangle(shell.getLocation().x, shell.getLocation().y, 
                                            shell.getSize().x, shell.getSize().y);
        initMouseMoveListener();
    }

    @Override
    public void nativeMouseMoved(NativeMouseEvent e) {
        if(!shell.isDisposed()){
            Point mousePoint = new Point(e.getX(), e.getY());
            //System.out.println("Point of mouse: " + mousePoint.x + ", " + mousePoint.y);
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
}
