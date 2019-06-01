class BaseClass
{
    int num = 100;
    
    public BaseClass()
    {
        System.out.println("BaseClass constructor");
    }
}

class SubClass extends BaseClass
{
    int num = 200;
    
    public SubClass()
    {
        System.out.println("SubClass constructor");
    }
    
    public void printValue()
    {
        System.out.println("SubClass variable: " + num);
        System.out.println("BaseClass variable: " + super.num);
    }
}

class Inheritance 
{    
    public static void main(String[] args)
    {
        SubClass s = new SubClass();
        s.printValue();
    }
}