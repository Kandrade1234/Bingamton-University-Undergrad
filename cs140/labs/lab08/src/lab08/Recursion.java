package lab08;

import java.util.ArrayList;

public class Recursion {

	private static final double DELTA = 1e-6;
	
	
	public static int factorial(int n){
		if(n == 0 || n ==1)
			return 1;
		else 
			return (n*factorial(n-1));
	}
	
	public static double squareRoot(double n){
		return squareRootHelper(n, 12.0);
	}
	private static double squareRootHelper(double n, double approx){
		if (n == 0)
			return 0;
		if (Math.abs(Math.pow(approx, 2)-n) <= DELTA)
		{
			return approx;
		}
		else
			return squareRootHelper(n, (approx + n/approx) / 2);
	}
	
	public static int sum(ArrayList<Integer> nums){
		return sumHelper(nums,0);
	}
	
	private static int sumHelper(ArrayList<Integer> nums, int index){
		if(index == nums.size()){
			return 0;
		}
		else 
		{
			return nums.get(index) + sumHelper(nums,index + 1);
		}
	}
	
	public static int sum(int[] nums){
		return sumHelper(nums, 0);
	}
	private static int sumHelper(int[] nums, int index){
		if(index == nums.length){
			return 0;
		}
		else{
			return nums[index] + sumHelper(nums,index + 1);

		}
	}
	public static int binomialCoefficient(int n, int k){
		if ((k == 0) || (n == k))
            return 1;
		if(k > n/2){
			return binomialCoefficient(n, n-k);
		}
        
            return  binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
	}
}