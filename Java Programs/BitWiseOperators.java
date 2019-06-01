class BitWiseOperators
{
    public static void main(String[] args)
    {
        char c1 = 'A', c2 = 'B';
        
        System.out.println("Value of c1: \t\t\t\t" + Integer.toBinaryString(c1));
        System.out.println("Value of c2: \t\t\t\t" + Integer.toBinaryString(c2));
        System.out.println("Value of c1 AND c2: \t\t\t" + Integer.toBinaryString(c1 & c2));
        System.out.println("Value of c1 OR c2: \t\t\t" + Integer.toBinaryString(c1 | c2));
        System.out.println("Value of c1 XOR c2: \t\t\t" + Integer.toBinaryString(c1 ^ c2));
        System.out.println("Value of NOT c1: \t\t\t" + Integer.toBinaryString(~c1));
        System.out.println("Value of shift left c1: \t\t" + Integer.toBinaryString(c1<<1));
        System.out.println("Value of shift right c1: \t\t" + Integer.toBinaryString(c1>>1));
        System.out.println("Value of unsigned shift right c1: \t" + Integer.toBinaryString(c1>>>1));

    }
}