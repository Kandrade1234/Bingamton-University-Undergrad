package exam02;

public class Modulo extends Sum{

	private int mod;
	
	public Modulo(int mod){
		this.mod = mod;
	}
	
	public int apply(int a, int b){
		
		return super.apply(a,b) % mod;
		
		
	}
	
}
