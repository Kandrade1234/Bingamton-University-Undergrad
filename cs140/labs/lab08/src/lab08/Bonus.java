package lab08;

public class Bonus {
	public static void main(String []args){
		printPascalsTriangle(5);
	}




	public static void printPascalsTriangle(int limit){
	
		for ( int i = 0; i < limit+1; i++){
			for (int j = 0; j <= i; j++){
				 System.out.print(Recursion.factorial(i) / (Recursion.factorial(j) * Recursion.factorial(i- j)) + " ");		
		}
			 System.out.println(); 
	
		}

	}
}
