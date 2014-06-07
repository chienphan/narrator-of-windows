package now.lib.define;

public class DefineEngineName {
    //TODO: After implement "Microsoft Translator", we need get list engine name from file 
    public static final String TRANSLATOR_ENGINE_GOOGLE 	= "Google Translator";
    public static final String TRANSLATOR_ENGINE_MICROSOFT 	= "Microsoft Translator";

    public static final String[] getAllEngineName(){
        return new String[]{TRANSLATOR_ENGINE_GOOGLE};
    }
}
