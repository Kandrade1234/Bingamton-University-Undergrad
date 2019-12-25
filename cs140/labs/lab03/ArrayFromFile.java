package lab03;
import java.io.File;
import java.util.Scanner;
import java.util.Arrays;
public class ArrayFromFile {
    
    private int [] array;
    public ArrayFromFile(String filename) {
        try (Scanner sc = new Scanner(new File(filename))) {
            array = new int[sc.nextInt()];
            for (int i = 0; i < array.length; i++)
            {
                array[i] = sc.nextInt();
            }
            
            
        } catch (Exception e) {
            array  = new int [0];
        }
    }
    public int [] getArray ()
    {
        return array;
    }
    
    public String toString ()
    {
        return Arrays.toString(array);
        
    }
    public void removeOddElements()
    {
        int numEvens = 0;
        int index = 0;
        for (int i : array)
        {
            if (i%2 == 0)
                ++numEvens;
        }
        int[] temp = new int[numEvens];
        for (int i : array)
        {
            
            if( i%2 == 0)
            {
                temp[index] = i;
                index++;
            }
        }
        array = temp; 
    }
    
    
    
}
