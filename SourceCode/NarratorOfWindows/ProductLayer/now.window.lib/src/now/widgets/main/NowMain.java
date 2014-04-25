/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

//import now.lib.tcp.NowServerSocket;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Administrator
 */
public class NowMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
            //        Thread notificationThread = new Thread(new Runnable() {
//
//            @Override
//            public void run() {
//                NowServerSocket.getInstance().startListening();
//            }
//        });
//        notificationThread.start();
                
//        NowSystemTray.getInstance().showSystemTray();
        String exePath = "f:\\My_Data\\narrator-of-windows\\SourceCode\\NarratorOfWindows\\bin\\Debug_32\\now.play.exe";
        String arg = "\\data\\lesson001.dat";
        try {
            Process process = new ProcessBuilder( exePath, arg ).start();
        } catch (IOException ex) {
            Logger.getLogger(NowMain.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}