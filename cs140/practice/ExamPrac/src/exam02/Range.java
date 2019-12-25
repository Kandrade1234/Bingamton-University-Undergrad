package exam02;

public class Range extends MinMax{

	public Range(double[] input) {
		super(input);
	}

	public double measure(){
		return super.value() - super.measure();
	}
	
	public double value(){
		if((super.measure() / super.value()) == 0)
			throw new IllegalArgumentException("cannot doivide by the minimum since it is zero");
		else 
			return super.measure() / super.value();
	
	}
	
	
	
	
}
