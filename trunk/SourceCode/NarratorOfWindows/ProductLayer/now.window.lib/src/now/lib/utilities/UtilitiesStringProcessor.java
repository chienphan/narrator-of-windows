/**
 * 
 */
package now.lib.utilities;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * @author gobom
 *
 */
public class UtilitiesStringProcessor {
	//http://docs.oracle.com/javase/7/docs/api/java/util/regex/Pattern.html
	public static final String REGEX_PUNCTUATION = "\\p{Punct}";
	public static final String REGEX_PUNCTUATION_SPEC = "[,.;:!?]";
	
	
	/**
	 * Split test for translate by using Google Translate API
	 * @param input text to split
	 * @return array text to translate
	 */
	@SuppressWarnings("unchecked")
	public static ArrayList<HashMap<Boolean, String>> split(String input){
		ArrayList<HashMap<Boolean, String>> result = new ArrayList<HashMap<Boolean, String>>();
		HashMap<Boolean, String> map = new HashMap<>();
		String temp = "";
		
		if(!input.isEmpty()){
			for (int index = 0; index < input.length(); index++){
				if(String.valueOf(input.charAt(index)).matches(REGEX_PUNCTUATION_SPEC)){
					
					map.put(true, temp);
					result.add((HashMap<Boolean, String>)map.clone());
					map.clear();
					
					map.put(false, String.valueOf(input.charAt(index)));
					result.add((HashMap<Boolean, String>)map.clone());
					map.clear();
					temp = "";
				}
				else{
					temp += String.valueOf(input.charAt(index));
				}
			}
			map.put(true, temp);
			result.add((HashMap<Boolean, String>)map.clone());
		}
		return result;
	}
}
