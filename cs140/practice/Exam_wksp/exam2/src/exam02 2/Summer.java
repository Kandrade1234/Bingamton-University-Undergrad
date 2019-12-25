package exam02;

public class Summer {

	private double [] array;
	
	
	public Summer(double [] input){
		array = input;
	}
	
	
	
	//sum of all doubles
	public double measure(){
		double sum = 0;
		
		for(int i =0; i < array.length; i++){
			sum += array[i];
		}
		return sum;
	}
	
	
	//number of doubles 
	public int value(){
		//-1????
		return array.length;
	}
}
