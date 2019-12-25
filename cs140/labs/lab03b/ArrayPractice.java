package lab03;

public class ArrayPractice {
	
	
	
public static double average(int[] array)
{
		double avg = 0.0;
		if (array == null)
			throw new IllegalArgumentException("array is null");	
		else if (array.length == 0)
			return 0.0;
	   
		else 
		{ 
			for (int i =0; i < array.length; i++)
			{
				avg += array[i];
			}
		avg = avg / array.length;
	    return avg;
		}
		
}
	
public static int[] evenIndicesOnly(int[] array) {
	int count= 0;
	int index = 0 ;
	int [] temp;
	
	if (array==null)
		return null;
	else if (array.length == 0)
	{
		return array;
	}
	
	else 
	{
		for (int i = 0; i < array.length; i++)
		{
			if (i % 2 == 0  )
				count++;
		}
		temp = new int [count];
		for (int i = 0; i < array.length; i++)
		{
			if (i % 2 == 0  )
			{
				temp [index] = array[i];
				index++;
			}
		}
	}
	return temp;

}
public static boolean isIncreasing(int[] array) 
{
	boolean check = true;

	if (array == null)
		return true;
	else if (array.length == 0)
		return true;
	else 
	{
		for (int i = 0; i < array.length; i++)
		{
			for (int j = i+1; j < array.length; j++)
			{
				if (array[i] >= array[j])
					check = false;
			}
		}
	}
	return check;	
}
	
public static int[] reverse(int[] array) 
{
	int[] temp = new int [0];
	int counter = 0;
	if (array == null)
		return null;
	else if (array.length == 0)
		return temp;
	else
	{		
		temp = new int[array.length];
		
		for (int i =array.length-1; i >= 0; i-- )
		{
				temp[counter] = array[i];
				counter++;
		}
	}		
		return temp;
}
public static int[] concatenate(int[] arr1, int[] arr2) {
int[] concat =  new int [0];
int counter = 0;	
	if(arr1 == null ||  arr2 == null)
		throw new IllegalArgumentException("array is null");	
	else if (arr1.length == 0 ||  arr2.length == 0)
		return concat;
	else 
	{
		concat = new int [arr1.length+arr2.length];
		for (int i =0; i <arr1.length; i++)
		{
			concat[counter] = arr1[i];
			counter++;
		}
		for (int j =0; j <arr2.length; j++)
		{
			concat[counter] = arr2[j];
			counter++;
		}
	}
	return concat;
}

public static int[] endToEnd(int[] arr1, int[] arr2) {
return concatenate (arr1, reverse(arr2));	
}

public static void reverseInPlace(int[] array)
{
	if (array == null)
		array = null;
	else if (array.length == 0)
	    array = new int [0];
	else
	{
		int left = 0 ;
		int right = array.length-1;
		while (left < right)
		{
			int temp = array [left];
			array [ left] = array [ right];
			array [ right] = temp;
			
			left++;
			right--;
		}
		
	}
}


	
	
}
