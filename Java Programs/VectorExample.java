import java.util.Vector;

class VectorExample
{
    public static void main(String[] args)
    {
         Vector vec = new Vector();
         
         vec.add("string");
         vec.add(52);
         vec.add((float) 52);
         vec.add((double) 52);
         vec.add(true);
         
         System.out.println(vec);
    }
}