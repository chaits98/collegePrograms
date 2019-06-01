import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class StringBufferExample
{
    public static void main (String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter string: ");
        String s = reader.readLine();
        StringBuffer sb = new StringBuffer(s);
        
        System.out.println("Length of string \"" + sb + "\": " + sb.length());
        System.out.println("Capacity of string \"" + sb + "\": " + sb.capacity());
        
        sb.append("hehe");
        System.out.println("Appended string: " + sb);

        sb.insert(0, 5);
        System.out.println("String afer insertion: " + sb);
        
        sb.reverse();
        System.out.println("String afer reverse: " + sb);
    }
}
