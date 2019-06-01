import java.util.Scanner;

class StringManipulation 
{
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        String mString1, mString2;
        int pos;
        char ch;
        
        System.out.println("Enter first String");
        mString1 = in.nextLine();
        System.out.println("String length: " + mString1.length());
        
        System.out.println("Enter second String");
        mString2 = in.nextLine();
        System.out.println("String length: " + mString2.length());
        
        System.out.println("Enter position to get character for string 1");
        pos = Integer.parseInt(in.nextLine());
        System.out.println("Character at position " + pos + " is: " + mString1.charAt(pos - 1));

        System.out.println("Equals \""+ mString2 + "\": " + mString1.equals(mString2));
        System.out.println("CompareTo \"" + mString2 + "\": " + mString1.compareTo((mString2)));
        System.out.println("CompareToIgnoreCase \"" + mString2 + "\": " + mString1.compareToIgnoreCase((mString2)));
        
        System.out.println("Enter character to get position for string 1");
        ch = in.nextLine().charAt(0);
        System.out.println("IndexOf \"" + ch + "\": " + (mString1.indexOf(ch) + 1));
        System.out.println("Concatenation:  " + mString1.concat(mString2));
    }
}