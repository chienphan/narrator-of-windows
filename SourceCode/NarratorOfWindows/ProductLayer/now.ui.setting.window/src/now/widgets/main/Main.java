package now.widgets.main;

import now.lib.jni.*;

public class Main {

	public static void main(String[] args) {
		String helpText 	= "";
		String signature 	= "";
		String controlType	= "";
		
		while (true) {
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
				controlType = NowJNICaller.getInstance().getControlProperty(signature, "LocalizedControlTypeProperty");
				helpText 	= NowJNICaller.getInstance().getUIInformation(signature);
				
				System.out.println("Java>>" + controlType + " - " + helpText);
			}
		}
	}

}
