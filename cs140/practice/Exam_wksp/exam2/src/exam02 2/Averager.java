package exam02;

public class Averager extends Summer {

	public  Averager(double [] array){
		super(array);
	}
	
	public double measure(){
		
		if (super.value() == 0)
			return -1;
		return super.measure() / super.value();
		
		
		
	}
	
	
}
