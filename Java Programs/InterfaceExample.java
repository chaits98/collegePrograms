interface FirstInterface
{
    void printMessage(String s);
    void printDontPrint();
}

public final class InterfaceExample implements FirstInterface
{
    InterfaceExample()
    {
        System.out.println("Four");
    }
    
    static
    {
        System.out.println("One");
    }
    
    {
       // printDontPrint();
       // printMessage("Three");
        System.out.println("Three");
    }
    
    public static void main(String[] args)
    {
        System.out.println("Two");
        InterfaceExample a = new InterfaceExample();
        System.out.println("Five");
        InterfaceExample b = new InterfaceExample();
    }
    
    @Override
    public void printDontPrint()
    {
        System.out.println("Don\'t print");
    }
    
    @Override
    public void printMessage(String s)
    {
        System.out.println("Message is \"" + s + "\"");
    }

}