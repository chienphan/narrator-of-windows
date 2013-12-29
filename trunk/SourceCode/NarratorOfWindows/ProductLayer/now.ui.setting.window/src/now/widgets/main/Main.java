package now.widgets.main;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Shell;

import now.lib.jni.*;

public class Main {

	public static void main(String[] args) {
		String informationt 	= "";
		String signature 	= "";
		String localizedControlType	= "";
		
		///////////////////////////////
		Display display = new Display();
	    Shell shell = new Shell(display);
	    shell.setText("Debug window");
	    shell.setBounds(0, 0, 400, 200);
	    //shell.setSize(400, 200);
	    
	    Label label = new Label(shell, SWT.WRAP);
	    label.setBounds(10, 10, 300, 30);
	    label.setText("Default Text!");
	    
	    
	    shell.open();
	    while (!shell.isDisposed()) {
	      if (!display.readAndDispatch())
	        //display.sleep();
	      
	      ////////////////////////////////////////////////////
	      try {
				Thread.sleep(100);
			} 
			catch (InterruptedException e) {
				System.out.println("InterruptedException: " + e.getMessage());
			}
			
			signature = NowJNICaller.getInstance().getControlSignatureUnderMouse();
			
			//Do not need check the control is changed or not. 
			//If the control is changed, the signature will not null.
			if(!signature.isEmpty())
			{
				localizedControlType = NowJNICaller.getInstance().getControlProperty(signature, "LocalizedControlTypeProperty");
				informationt 	= NowJNICaller.getInstance().getUIInformation(signature);
				
				label.setText("Java>>" + localizedControlType + " - " + informationt);
				//System.out.println("Java>>" + localizedControlType + " - " + informationt);
			}
			//////////////////////////////////////////////
			
	    }
	    display.dispose();
	}

}
