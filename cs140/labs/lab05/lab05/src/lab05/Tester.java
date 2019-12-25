package lab05;

import java.util.Arrays;
import java.util.ArrayList;

public class Tester {

    public static void main(String[] args) {
        testDivision();
        testDivisionNullEmpty();
    	testFunWithStrings();
        testZipper();
        testZipperNullEmptyLength();
    }

    public static void testDivision() {
        Division set = new Division(new double[]{1,2,3,0,4,5,0,6,0,7,8,9,0});
        set.removeZeroes();
        set.divide(2);
        System.out.println("Expecting [0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5]");
        System.out.println("Received  " + set + "\n");
        
    }
    public static void testDivisionNullEmpty() {
    	//Null
    	try{
         Division set = new Division(null);
        set.divide(2);
    	
        System.out.println("NULL");
        System.out.println("Received  " + set + "\n");
    	}catch (IllegalArgumentException e){
    	System.out.println(e);
    	}
    	//empty
    	try{
        Division set = new Division(new double [0]);
        set.divide(2);
    	
        System.out.println("Empty");
        System.out.println("Received  " + set + "\n");
    	}catch (IllegalArgumentException e){
    	System.out.println(e);
    	}
    	//Division by 0
    	try{
        Division set = new Division(new double [3]);
        set.divide(0);
        	
        System.out.println("Empty");
        System.out.println("Received  " + set + "\n");
        }catch (IllegalArgumentException e){
        System.out.println(e);
        }
    	
    	
    }
    
    public static void testFunWithStrings() {
    	ArrayList<String> list1 = new ArrayList<String>(Arrays.asList("to", "cellphone", "truck", "fire"));
    	ArrayList<String> list2 = new ArrayList<String>(Arrays.asList("delicious", "copper", "blue", "red"));
    	FunWithStrings.swapMaxes(list1, list2);
        System.out.println("\nExpecting [to, delicious, truck, fire] [cellphone, copper, blue, red]");
        System.out.println("Received  " + list1 + " " + list2 + "\n");
    }

    public static void testZipper() {
        int ret[] = Zipper.zip(new int[]{1, 3, 5, 7}, new int[]{2, 4, 6, 8});
        System.out.println("Expecting [1, 2, 3, 4, 5, 6, 7, 8]");
        System.out.println("Received  " + Arrays.toString(ret));
    }

    public static void testZipperNullEmptyLength() {
       //Uneven
    	try{int ret[] = Zipper.zip(new int[]{1, 3, 5, 7, 5}, new int[]{2, 4, 6, 8});
        System.out.println("Received  " + Arrays.toString(ret));
        }
        catch (IllegalArgumentException e){
        	System.out.println(e);
        }
        //empty with eneven length
        try{int ret[] = Zipper.zip(new int[0], new int[]{2, 4, 6, 8});
        System.out.println("Received  " + Arrays.toString(ret));
        }
        catch (IllegalArgumentException e){
        	System.out.println(e);
        }
        //null pointer
        int[] arr = null;
        try{int ret[] = Zipper.zip(arr, new int[]{2, 4, 6, 8});
        System.out.println("Received  " + Arrays.toString(ret));
        }
        catch (IllegalArgumentException e){
        	System.out.println(e);
        }
        
        int[] array1 = new int [0];
        int[] array2 = new int [0];
        try{
        int ret[] = Zipper.zip(array1, array2);
        System.out.println("Expecting []");
        System.out.println("Received  " + Arrays.toString(ret));
        }
        catch (IllegalArgumentException e){
        	System.out.println(e);
        }
        
        
       }


}
