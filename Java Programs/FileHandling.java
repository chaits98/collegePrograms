import java.io.*;
import java.security.AccessController;
import java.security.PrivilegedAction;

public class FileHandling
{
    public static void main(String[] args)
    {
        final String msg = "My message";

        
        AccessController.doPrivileged(new PrivilegedAction<Boolean>()
        {
            public Boolean run()
            {
                try
                {
                    String path = "msg.txt";
                    PrintWriter writer = new PrintWriter(path, "UTF-8");
                    writer.println(msg);
                    writer.close();
                }
                
                catch(UnsupportedEncodingException e)
                {
                    e.printStackTrace();
                }

                catch(FileNotFoundException e)
                {
                    e.printStackTrace();
                }

                return true;
            }
        });

        
        try
        {
            BufferedReader reader = new BufferedReader(new FileReader("msg.txt"));
            String st;

            while((st = reader.readLine()) != null)
            {
                System.out.println(st);
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();        
        }
        // catch(FileNotFoundException e)
        // {
        //     e.printStackTrace();        
        // }
    }
}