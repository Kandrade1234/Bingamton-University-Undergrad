package assignment06;
import java.util.Arrays;

public class Testarr {
	public static void main(String[] args) {
		int[][] test = {{1,7,2,4}, {3,5}, {4,0,2,1,4}};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));		
		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.rowAverages(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		test = new int[][] {{1,7,2,4}, {3,5,6,1}, {5,5,1,1}, {4,0,2,1,}};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));		
		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.rowAverages(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		test = new int[][] {};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));		
		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.rowAverages(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		test = new int[][] {{}, {}, {}, {}};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));		
		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.rowAverages(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		test = new int[][] {{1,7,2,4}, {}, {4,0,2,1,4}};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));		
		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.rowAverages(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		test = new int[][] {{}, {}, {4,0,2,1,4}};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));
		System.out.println("am i missing a line here");

		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		System.out.println("yeah maybe");
		test = new int[][] {{0}, {}, {0,0}};
		System.out.println(Arrays.toString(Array2Dexamples.rowSums(test)));		
		System.out.println(Arrays.toString(Array2Dexamples.columnSums(test)));
		System.out.println(Arrays.toString(Array2Dexamples.rowAverages(test)));
		System.out.println(Arrays.toString(Array2Dexamples.columnAverages(test)));
		test = null;
		try {
			Array2Dexamples.diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 1 OK for null");
		}
		try {
			Array2Dexamples.antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 2 OK for null");
		}
		test = new int[][] {{1,7,2,4}, null, {4,0,2,1,4}};
		try {
			Array2Dexamples.diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 3 OK for null");
		}
		try {
			Array2Dexamples.antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 4 OK for null");
		}
		test = new int[][] {{1,7,2}, {1,7,2}, {4,0,2,1,4}};
		try {
			Array2Dexamples.diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 5 OK for null");
		}
		try {
			Array2Dexamples.antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 6 OK for null");
		}
		test = new int[][] {{1,7,2}, {1,7}, {4,0,2}};
		try {
			Array2Dexamples.diagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got diagonal exception 7 OK for null");
		}
		try {
			Array2Dexamples.antiDiagonalSum(test);
		} catch(IllegalArgumentException e) {
			System.out.println("got antidiagonal exception 8 OK for null");
		}
		test = new int[][] {{1,7,2,4}, {3,5,6,1}, {5,5,1,1}, {4,0,2,1,}};
		System.out.println(Array2Dexamples.antiDiagonalSum(test));
		System.out.println(Array2Dexamples.diagonalSum(test));
	}
}
