package exam02;

public class MinMax {
	private double [] array;
	public MinMax(double [] input){
		array = input;
	}
	
	public double measure(){
	double min = array[0];
	for(int i =0; i < array.length; i++){
		if(array[i] < min )
			min = array [i];
	}
	return min;
	
	}
	
	public double value(){
		double max = array[0];
		for(int i =0; i < array.length; i++){
			if(array[i] > max )
				max = array [i];
		}
		return max;
		
		
		
		
		
		
	}
	
	
	
}
