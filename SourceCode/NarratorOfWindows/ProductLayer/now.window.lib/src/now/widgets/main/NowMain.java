/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.widgets.main;

//import now.lib.tcp.NowServerSocket;

import now.lib.tcp.NowServerSocket;

/**
 *
 * @author Chien.Phan
 */
public class NowMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Thread notificationThread = new Thread(new Runnable() {

            @Override
            public void run() {
                NowServerSocket.getInstance().startListening();
            }
        });
        notificationThread.start();
        
        NowSystemTray.getInstance().showSystemTray();
    }
}