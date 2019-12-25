package assignment06;

public class Challenge {

	private int[][] array;
	private int[] colSums;
	private int [] rowSums;
	private int diagSum; 
	private int antidiagSum;

	public Challenge(int[][] array, int[] colSums, int[] rowSums, int diagSum, int antidiagSum){
		this.array = array;
		this.colSums = colSums;
		this.rowSums = rowSums;
		this.diagSum = diagSum;
		this.antidiagSum = antidiagSum;
	}
	public String view(int[][] arr){

		StringBuilder sb = new StringBuilder();
		sb.append("\t"+ "\t"+ "\t" + "\t" + antidiagSum +"\n");
		for(int i =0; i < arr.length; i++){
			for (int j =0; j < arr[i].length; j++){
				sb.append(arr[i][j] + "\t" );
			}
			sb.append(rowSums[i]);
			sb.append("\n");
		}

		for(int i =0; i < colSums.length; i++){
			sb.append(colSums[i]+ "\t" );
		}
		sb.append(diagSum);
		return sb.toString();
	}

	public int countZeros(int[][] arr){

		int counter =0;
		for(int row =0; row < arr.length; row++){
			for(int col =0; col < arr[row].length; col++){
				if(arr[row][col] == 0)
					counter++;
			}
		}
		return counter;
	}
	class Pair {
		int row; int col;
		public Pair(int x, int y) {
			row = x;
			col = y;
		}
	}


	public Pair nextZero(int[][] arr) {
		Pair zero = null;
		for(int row=0; row < arr.length; row++){
			for (int col =0; col < arr[row].length; col++){
				if(arr[row][col] == 0 ){
					zero = new Pair(row, col);
				
					
					return zero;
				}
			}
		}
		return zero;

	}


	public boolean feasible(int[][] arr){
		if(Array2Dexamples.antiDiagonalSum(arr) > antidiagSum)
			return false;
		if(Array2Dexamples.diagonalSum(arr) > diagSum )
			return false;
		int i =0;
		while (i >=0 && i <=3){
			if(Array2Dexamples.rowSums(arr)[i] > rowSums[i])
				return false;
			i++;
		}
		int j=0;
		while (j >=0 && j <=3){
			if(Array2Dexamples.columnSums(arr)[j] > colSums[j])
				return false;
			j++;
		}
		return true;
	}
	
	public boolean solved(int[][] arr){
		if(Array2Dexamples.antiDiagonalSum(arr)!= antidiagSum)
			return false;
		if(Array2Dexamples.diagonalSum(arr) != diagSum)
			return false;
		int i =0;
		while(i >=0 && i <=3){
			if(Array2Dexamples.rowSums(arr)[i] != rowSums[i] ||Array2Dexamples.columnSums(arr)[i] != colSums[i])
				return false;
			i++;
		}
	
		return true;
	}
	private int[][] duplicate(int[][] arr){
		int duplicate[][] = new int[arr.length][];
		for(int row=0; row < arr.length; row++){
			duplicate [row] = new int [array[row].length];
			for(int col =0; col < duplicate[row].length; col++){
				duplicate [row][col] = arr[row][col];
			}
		}
		return duplicate;		
	}

	public void solve(int [][] arr){
		if(countZeros(arr) >0){
			Pair p = nextZero(arr);
			for(int i =1; i <= 9; i++){
				arr[p.row][p.col]=i;
				if(countZeros(arr) == 0 && solved(arr)){
					System.out.print("\nSOLUTION\n" + view(arr));
					
				}
				if(countZeros(arr) > 0 && feasible(arr)){
					solve(duplicate(arr));
				}
			}
		}
	}
	public static void main(String[] args) {
		Challenge puzzle = new Challenge(new int[][]{{2,0,0,0},{0,0,0,1},{0,5,0,0},{0,0,6,0}},
				new int[]{8,9,15,28}, new int[]{15,11,17,17}, 14, 20);
		System.out.println(puzzle.view(puzzle.array));
		puzzle.solve(puzzle.duplicate(puzzle.array));
	}
}