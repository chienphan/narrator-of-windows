/**
 * 
 */
package now.lib.utilities;

/**
 * @author gobom
 *
 */
public class UtilitiesStringProcessor {
	public static final String REGEX = "\\p{Punct}";
	public static String[] split(String input){
		String[] result = input.split(REGEX);
		return result;
	}
}
