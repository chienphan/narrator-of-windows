/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package now.lib.tcp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.util.ArrayList;
import now.lib.constant.NowConst;
import now.lib.utilities.UtilitiesDevice;
import now.lib.utilities.UtilitiesFileTXT;
import org.eclipse.swt.widgets.Display;
import org.mihalis.opal.notify.Notifier;

/**
 *
 * @author Chien Phan
 */
public class NowServerSocket {
    private static NowServerSocket m_instance = null;
    private ServerSocket m_serverSocket = null;
    
    private NowServerSocket(){
        boolean isCreateServerSocket = false;
        int defaultPort = NowConst.NOW_TCP_IP_DEFAULT_PORT;
        
        while(isCreateServerSocket == false){
            try {
                m_serverSocket = new ServerSocket(defaultPort, 0, InetAddress.getByAddress(new byte[]{(byte)127, (byte)0, (byte)0, (byte)1}));
                isCreateServerSocket = true;
            } 
            catch (IOException ex) {
                defaultPort++;
            }
        }
        //Write the port number to config file
        if(isCreateServerSocket == true){
            String tcpConfigFilePath = UtilitiesDevice.getCurrentDirectory() + NowConst.NOW_BACKSLASH + NowConst.NOW_TCP_CONFIG_FILE;
            UtilitiesFileTXT tcpConfigFile = new UtilitiesFileTXT(tcpConfigFilePath);
            ArrayList<String> data = new ArrayList<String>();
            data.add("port" + NowConst.NOW_DELIMITER + String.valueOf(defaultPort));
            tcpConfigFile.writeLargerTextFile(tcpConfigFilePath, data);
        }
    };
    
    public static NowServerSocket getInstance(){
        if (m_instance == null) {
            m_instance = new NowServerSocket();
        }
        return m_instance;
    }
    
    public void startListening(){
        try {    
            
            //wait for accept the session
            while(true){
                Socket insocket = m_serverSocket.accept( );
                Charset unicodeCharSet = Charset.forName("UTF-8");
                BufferedReader in = new BufferedReader(new InputStreamReader(insocket.getInputStream(), unicodeCharSet));
                byte[] arrayByte = in.readLine().getBytes(unicodeCharSet);

                final String outPrint = new String(arrayByte, unicodeCharSet);
                System.out.println(outPrint);
                //TODO: Display notification here!!!
                Display.getDefault().syncExec(new Runnable() {

                    @Override
                    public void run() {
                        Notifier.notify("Data message!!!", outPrint);
                    }
                });
                insocket.close();
            }
        }
        catch (IOException e) {
        } 
    }
}
