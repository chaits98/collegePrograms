public class ExceptionHandling 
{
    public static void main(String[] args)
    {
        int n = 20,d = 0;
        float frac;
	
	
        try
        {
            frac = n/d;
	    System.out.println(frac);
        }
        catch(ArithmeticException e)
        {
            System.out.println(e);
        }
	// casting frac to a float would have prevented this exception
	// since you can represent Infinity in IEEE-754 standard
        finally
        {
            System.out.println("finally 1");
	    frac = (float) n/d;
	    System.out.println(frac);
        }
        try
        {
             int ar[] = {1};
             ar[2] = 0;
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e);
        }
        finally
        {
            System.out.println("finally 2");
        }
    }
}

