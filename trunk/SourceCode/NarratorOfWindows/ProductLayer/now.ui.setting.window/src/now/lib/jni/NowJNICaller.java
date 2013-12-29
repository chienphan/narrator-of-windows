package now.lib.jni;

import now.lib.utilities.NowUtilDevice;

public class NowJNICaller {
	private static NowJNICaller m_instance = null;
	
	/**
	 * The constructor.
	 */
	private NowJNICaller()
	{
		String libPath = NowUtilDevice.getCurrentDirectory() + "\\now.lib.jniwrapper.dll";
		NowUtilDevice.loadLibrary(libPath);
	}
	
	/**
	 * Get instance of this class.
	 * @return The singleton instance.
	 */
	public static NowJNICaller getInstance() {
		if (m_instance == null) {
			m_instance = new NowJNICaller();
		}
		return m_instance;
	}
	
	/**
	 * Get control under mouse position. This method is beginner of get control element at point follow.
	 * @return The signature of control is found.
	 * <br>If the control under mouse position is not changed, it return empty string.
	 */
	public native String getControlSignatureUnderMouse();

	/**
	 * Get information of control, the information can be tool-tip or any information of control if need. <br>
	 * The information dependent of control's type.
	 * @param signature Signature to define the control.
	 * @return information.
	 */
	public native String getUIInformation(String signature);
	
	/**
	 * Get property of control.
	 * @param signature Signature to define the control.
	 * @param propertyName Property name.
	 * @return Property value.
	 */
	public native String getControlProperty(String signature, String propertyName);
}
