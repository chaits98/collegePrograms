import java.util.*;

public class HashmapExample
{
    public static void main(String[] args)
    {
        HashMap<String, Object> map = new HashMap<>();

        map.put("integer", (Object) 20);
        map.put("string", (Object) "Hello");

        // String strVal = (String) map.get("string");
        // Integer intVal = (Integer) map.get("integer");


        System.out.println("String: " + map.get("string"));
        // System.out.println("String: " + strVal);
        System.out.println("Integer: " + map.get("integer"));
        // System.out.println("Integer: " + intVal);
    }
}