package lab05;
import java.util.Arrays;


public class Zipper
{

	public static int[] zip(int[] arr1, int[] arr2)
	{
	int[]  arrN = new int [0] ;
	if ((arr1 == null || arr2 == null) || arr1.length != arr2.length)
		throw new IllegalArgumentException("bad Input");

	if (arr1.length==0 && arr2.length == 0)
		return arrN;
	
	arrN = new int [arr1.length + arr2.length];	
	
	int index = 0;
	
	for (int i = 0; i < arr1.length; i++)
	{
		
        arrN[index] = arr1[i];
        index++;
        arrN[index] = arr2[i];
        index++;
	}

	return arrN;


	}


}
