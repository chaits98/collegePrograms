class CommandLine 
{
    public static void main(String[] args)
    {
        for(String s : args)
        {
            System.out.println(s);
        }
        System.out.println(args.length);
    }
}