package now.lib.jni;

import now.lib.constant.NowConst;
import now.lib.utilities.UtilitiesDevice;

public class JNICaller {
	private static JNICaller m_instance = null;
	
	/**
	 * The constructor.
	 */
	private JNICaller()
	{
            String libPath = "";
            if("1".equals(UtilitiesDevice.getEnvironmentVariableValue(NowConst.NOW_DEBUG_MODE))){
                libPath = UtilitiesDevice.getEnvironmentVariableValue(NowConst.NOW_DEBUG_DIRECTORY) + "\\now.lib.jniwrapper.dll";
            }
            else{
                libPath = UtilitiesDevice.getCurrentDirectory() + "\\now.lib.jniwrapper.dll";
            }
	
            if(!"".equals(libPath)){
                UtilitiesDevice.loadLibrary(libPath);
            }
	}
	
	/**
	 * Get instance of this class.
	 * @return The singleton instance.
	 */
	public static JNICaller getInstance() {
		if (m_instance == null) {
			m_instance = new JNICaller();
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
