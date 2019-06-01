class JavaApplication1
{    
    public static void main(String[] args)
    {
        int a = 20, b = 13, c = 44;
        if(a > b)
        {
            if(a > c)
            {
                System.out.println("a is the largest");
            }
            else
            {
                System.out.println("c is the largest");
            }
        }
        else
        {
            if(b > c)
            {
                System.out.println("b is the largest");
            }
            else
            {
                System.out.println("c is the largest");
            }
        
        }
    }
}
