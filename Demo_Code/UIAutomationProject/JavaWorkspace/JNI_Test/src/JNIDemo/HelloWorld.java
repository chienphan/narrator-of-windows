package JNIDemo;

import java.nio.file.Path;
import java.nio.file.Paths;

public class HelloWorld {

	public native void displayMessage(int nIndex);
	static 
	{
		try{
		Path currentRelativePath = Paths.get("");
		String s = currentRelativePath.toAbsolutePath().getParent().getParent().toString();
		System.out.println("Current relative path is: " + s);
		
		System.load(s + "//bin//x64//Debug//JNIWrapper.dll");
		
		}
		catch(Exception ex)
		{
			System.out.println(ex.getMessage());
		}
	}
}
