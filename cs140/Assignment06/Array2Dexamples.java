package assignment06;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Array2Dexamples {


	//arr.length is the number of ROWS
	//arr[i].length is the length of the ith row (Columns) 
	public static int[] rowSums(int [][] arr){

		int [] sum = new int[arr.length];
		for(int i =0; i < arr.length; i++){

			for (int j =0; j < arr[i].length; j++)
				sum[i] += arr[i][j];
		}
		return sum;
	}

	public static int[] columnSums(int[][] arr) 
	{		//Finds the max columns a row can have
		int max =0;
		for(int i =0; i < arr.length; i++){
			max = Math.max(arr[i].length, max);
		}
		//Intialize
		int [] colSum = new int[max];

		//Makes sure that the columns dont go past its own max 
		for(int col =0; col < max; col++){
			//we will iterate through all the rows up to the length of the rows
			for (int row =0; row < arr.length; row++)
				if(col < arr[row].length) 		//will check if the column we are in is less than the length of rows so it doesnt try to go out of bounds
					colSum[col] += arr[row][col];	//adds at ith position and row is increased so we iterate downwards instead of horizontal
		}
		return colSum;
	}
	public static double[] rowAverages(int[][] arr)
	{

		double avg[] = new double[arr.length]; //intantiated to the length of number of rows
		for (int row = 0; row < arr.length; row++){
			double temp = 0;
			for(int col =0; col < arr[row].length; col++){

				temp += arr[row][col];
			}
			temp = (double)( temp /  arr[row].length); 
			avg[row] = temp;
			if(arr[row].length == 0){
				avg[row] = 0;
			}
		}
		return avg;
	}
	public static double[] columnAverages(int[][] arr){
		int max =0;

		for(int i =0; i < arr.length; i++){
			max = Math.max(arr[i].length, max);
		}
		//Intialize
		double [] avg = new double[max];
		//Makes sure that the columns dont go past its own max 
		for(int col =0; col < max; col++){
			double sum =0;
			double counter =0;
			//we will iterate through all the rows up to the length of the rows
			for (int row =0; row < arr.length; row++){
				if(col < arr[row].length) {		//will check if the column we are in is less than the length of rows so it doesnt try to go out of bounds
					sum += arr[row][col];		//adds at ith position and row is increased so we iterate downwards instead of horizontal
					counter++;
				}
			}
			sum = (double) (sum / counter);
			avg[col] = sum;
		}
		return avg;
	}
	public static int diagonalSum(int[][] arr){

		if(arr == null)
		{
			throw new IllegalArgumentException ("Array cannot be null");
		}
		int sum =0;
		for(int row =0; row < arr.length; row++){
			if(arr[row] == null || arr[row].length != arr.length){
				throw new IllegalArgumentException ("Array cannot be null");
			}
			sum += arr[row][row];
		}
		return sum;
	}

	public static int antiDiagonalSum(int[][] arr) 
	{
		if(arr == null)
		{
			throw new IllegalArgumentException ("Array cannot be null");
		}
		int sum = 0;
		int counter =0;
		for(int row = arr.length-1; row >= 0; row--){
			if(arr[row] == null || arr[row].length != arr.length){
				throw new IllegalArgumentException ("Array cannot be null");
			}
			sum += arr[counter][row];
			counter++;
		}
		return sum;
	}

	
public static void main(String args[]){

		int[][] test = {{1,7,2,4}, {3,5}, {4,0,2,1,4}};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = new int[][] {{1,7,2,4}, {3,5,6,1}, {5,5,1,1}, {4,0,2,1,}};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = new int[][] {};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = new int[][] {{}, {}, {}, {}};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = new int[][] {{1,7,2,4}, {}, {4,0,2,1,4}};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = new int[][] {{}, {}, {4,0,2,1,4}};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = new int[][] {{0}, {}, {0,0}};
		System.out.println(Arrays.toString(rowSums(test)));		
		System.out.println(Arrays.toString(columnSums(test)));
		System.out.println(Arrays.toString(rowAverages(test)));
		System.out.println(Arrays.toString(columnAverages(test)));
		test = null;
		try {
			diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 1 OK for null");
		}
		try {
			antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 2 OK for null");
		}
		test = new int[][] {{1,7,2,4}, null, {4,0,2,1,4}};
		try {
			diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 3 OK for null");
		}
		try {
			antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 4 OK for null");
		}
		test = new int[][] {{1,7,2}, {1,7,2}, {4,0,2,1,4}};
		try {
			diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 5 OK for null");
		}
		try {
			antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 6 OK for null");
		}
		test = new int[][] {{1,7,2}, {1,7}, {4,0,2}};
		try {
			diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 7 OK for null");
		}
		try {
			antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 8 OK for null");
		}
		test = new int[][] {{1,7,2,4}, {3,5,6,1}, {5,5,1,1}, {4,0,2,1,}};
		System.out.println(antiDiagonalSum(test));
		System.out.println(diagonalSum(test));
	}



}




