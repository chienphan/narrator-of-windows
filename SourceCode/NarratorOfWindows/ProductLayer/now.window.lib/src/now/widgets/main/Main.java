package now.widgets.main;


import com.gtranslate.Translator;

import now.lib.configuration.ConfigLanguage;
import now.lib.configuration.ConfigTranslateEngine;
import now.lib.jni.*;
import now.lib.define.DefineLanguageName;

public class Main {
	
	@SuppressWarnings("unused")
	private static void runDebug() {
//		String informationt 	= "";
//		String signature 	= "";
//		String localizedControlType	= "";
//		String vietnamese = "";
//		Translator translator = Translator.getInstance();
//	
//		///////////////////////////////
//		Display display = new Display();
//	    Shell shell = new Shell(display);
//	    shell.setText("Debug window");
//	    shell.setBounds(0, 0, 400, 200);
//	    //shell.setSize(400, 200);
//	    
//	    Label labelEng = new Label(shell, SWT.WRAP);
//	    labelEng.setBounds(10, 10, 380, 30);
//	    labelEng.setText("Default Text!");
//	    
//	    Label labelVie = new Label(shell, SWT.WRAP);
//	    labelVie.setBounds(10, 50, 380, 30);
//	    
//	    shell.open();
//	    while (!shell.isDisposed()) {
//	      if (!display.readAndDispatch())
//	        //display.sleep();
//	      
//	      ////////////////////////////////////////////////////
//	      try {
//				Thread.sleep(100);
//			} 
//			catch (InterruptedException e) {
//				System.out.println("InterruptedException: " + e.getMessage());
//			}
//			
//			signature = JNICaller.getInstance().getControlSignatureUnderMouse();
//			
//			//Do not need check the control is changed or not. 
//			//If the control is changed, the signature will not null.
//			if(!signature.isEmpty())
//			{
//				localizedControlType = JNICaller.getInstance().getControlProperty(signature, "LocalizedControlTypeProperty");
//				informationt 	= JNICaller.getInstance().getUIInformation(signature);
//				
//				labelEng.setText("Eng>>" + localizedControlType + " - " + informationt);
//				//vietnamese = translator.translate(informationt, Language.ENGLISH, Language.VIETNAMESE);
//				//labelVie.setText("Vie>>" + vietnamese);
//				//Translate by Google Translate API
//		        
//				String[] temp = informationt.split(",");
//		        String[] vieString = new String[100];
//				
//				try{
//		            for (int i = 0; i < temp.length; i++) {
////		                if(temp[i] == "," || temp[i] == "."){
////		                    vieString[i] = temp[i] + " ";
////		                    //System.out.println(vieString[i]);
////		                }
////		                else if(temp[i] == "\n"){
////		                    vieString[i] = temp[i];
////		                }
////		                else if(temp[i] == null){
////		                    //bo qua
////		                }
////		                else{
//		                    //vieString[i] = translator.translate(temp[i], Language.ENGLISH, Language.VIETNAMESE);
//		                    //System.out.println(vieString[i]);
////		                }
//		            }
//		        }
//		        catch(Exception e){
//		            e.printStackTrace();
//		        }
//		        for (int i = 0; i < vieString.length; i++) {
//		            if(vieString[i] != null){
//		            	vietnamese += vieString[i] + ", ";
//		            }
//		        }
//		        labelVie.setText("Vie>>" + vietnamese);
//		        vietnamese = "";
//				//System.out.println("Java>>" + localizedControlType + " - " + informationt);
//			}
//			//////////////////////////////////////////////
//			
//	    }
//	    display.dispose();
	}

//	public static void main(String[] args) {
//		//TODO: if you want to run debug to c++/c# follow, you should run method "runDebug"
//		//runDebug();
//		
//		//TODO: this method is used to run java follow.
//		runJavaFollow();
//	}
	
	private static void runJavaFollow(){
		ConfigTranslateEngine.getInstance().setTranslatorEngine(now.lib.define.DefineEngineName.TRANSLATOR_ENGINE_GOOGLE);
		ConfigLanguage.getInstance().setInputLanguage(DefineLanguageName.ENGLISH);
		ConfigLanguage.getInstance().setOutputLanguage(DefineLanguageName.VIETNAMESE);
		System.out.println(now.lib.translator.Translator.getInstance().translateAutoDetectInput("Hello everyone! i'm a machine."));
		System.out.println(now.lib.translator.Translator.getInstance().translateAutoDetectInput("Hello everyone! i'm a machine.",
				DefineLanguageName.FRENCH));
		//"Xin chÃ o táº¥t cáº£ má»�i ngÆ°á»�i! TÃ´i lÃ  má»™t mÃ¡y."
		//"Bonjour Ã  tous! Je suis une machine."
		
		now.lib.translator.Audio.getInstance().play("Xin chÃ o táº¥t cáº£ má»�i ngÆ°á»�i! TÃ´i lÃ  má»™t mÃ¡y");
	}
}