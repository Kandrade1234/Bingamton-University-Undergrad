package exam02;

public class Power extends Identity {

	private double exp;
	public Power (double exp){
		this.exp = exp;
	}
	
	public double apply(double n){
		return Math.pow(n, exp);
	}
	
	
}
