package lab03;
import java.util.Arrays;
public class ArrayTester
{
    public static void main(String[] args) {
        
        if (args.length == 1)
        {
            ArrayFromFile arrayInput = new ArrayFromFile(args[0]);
            System.out.println("This is what the output should contain: " );
            System.out.println(20);
            System.out.println(8);
            System.out.println(13);
            System.out.println(46);
            System.out.println(7);
            System.out.println("This is the text file: " );
            System.out.println(arrayInput.toString());
            System.out.println("The output expected: [20, 8, 16]");
            arrayInput.removeOddElements();
            System.out.println(arrayInput.toString());
            int[] array = new int [5];
            System.out.println(Arrays.toString(array));
            int n = 0;
            for (int i : array) {
                i = n;
                n++; // shorthand to increment by 1
            }
            System.out.println(Arrays.toString(array));
            String arr [] = {"Kevin", "likes", "apple", "pie"};
            for (String i : arr) {
                System.out.print(i);
                System.out.print(" ");

                System.out.print (i.length());
                System.out.print(" ");
                
            }
        }
        else throw new IllegalArgumentException("This program requires exacly 1 argument!!");
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}
