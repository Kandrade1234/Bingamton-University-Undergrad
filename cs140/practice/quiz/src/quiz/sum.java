package quiz;
import java.util.Arrays;
public class sum {
public static void main(String args[]){
	
	int[] arr = new int[]{7, -1, 5, 0,6,4,1,0,2};
	System.out.println(partialSum(arr));
	
	
	
	
}
	
	public static int partialSum(int [] arr)
	{
		
		int sum = 0;
		if(arr == null || arr.length ==0)
			return 0;
		else 
		{
			for (int i =0 ; i < arr.length; i++)
			{
				if (arr[i] != 0 )
					sum += arr[i];
				else 
					return sum;
			}
		}
		//return sum;
		
	}
	
}
