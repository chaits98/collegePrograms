import java.io.*;
import java.util.*;

public class FileIOExample
{
    FileOutputStream out = null;
    
    public void openWriteFile(String name, boolean append) throws IOException, FileNotFoundException
    {
        this.out = new FileOutputStream(name, append);
    }

    public void addData(String data) throws IOException, FileNotFoundException
    {
        this.out.write(data.getBytes());
    }

    public void readData(String filename) throws IOException, FileNotFoundException
    {
        File file = new File(filename); 
        Scanner sc = new Scanner(file); 
  
        sc.useDelimiter("\\Z"); 
  
        System.out.println(sc.next());
        sc.close();
    }

    public void closeFileStream() throws IOException, FileNotFoundException
    {
        if(out != null)
        {
            this.out.close();
            out = null;
        }
    }

    public static void main(String args[]) throws IOException, FileNotFoundException
    {
        FileIOExample file = new FileIOExample();
        int choice = 0;
        String filename, data;
        Scanner sc = new Scanner(System.in);
        while(choice != 4)
        {
            System.out.println("1. Open new file");
            System.out.println("2. Append to file");
            System.out.println("3. Open existing file");
            System.out.println("4. Exit");
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                    System.out.println("Enter name of file: ");
                    filename = sc.next();
                    file.openWriteFile(filename, false);
                    System.out.println("Enter string to file: ");
                    sc.nextLine();
                    data = sc.nextLine();
                    file.addData(data);
                    file.closeFileStream();
                    break;

                case 2:
                    System.out.println("Enter name of file: ");
                    filename = sc.next();
                    file.openWriteFile(filename, true);
                    System.out.println("Enter string to file: ");
                    sc.nextLine();
                    data = sc.nextLine();
                    file.addData(data);
                    file.closeFileStream();
                    break;

                case 3:
                    System.out.println("Enter name of file: ");
                    filename = sc.next();
                    file.readData(filename);
                    break;

                default:
                    break;
            }
        }
        sc.close();
    }
}