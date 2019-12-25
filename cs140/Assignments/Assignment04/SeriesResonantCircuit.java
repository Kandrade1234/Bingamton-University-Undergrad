package assignment04;

public class SeriesResonantCircuit extends ResonantCircuit {
	private double resistance;
	private double capacitance;
	private double inductance;
	
	
	static private double computeBandwidth(double r, double l)
	{
		if ( l == 0)
			throw new IllegalArgumentException("inputs cannot be zero");
		
		return r/l;
	
	}
	
	static private double computeFrequency(double c, double L)
	{
		if ( c == 0 || L == 0)
				throw new IllegalArgumentException("inputs cannot be zero");
		
		return Math.sqrt(1/(L*c));		
	}
	
	public SeriesResonantCircuit(double r, double c, double l)
	{
		super(computeFrequency(c, l), computeBandwidth(r, l), 1/r);
		resistance = r;
		capacitance = c;
		inductance = l;
	}
	public void display()
	{
		super.display();
		System.out.println("\t" +"resistance: " + resistance);
		System.out.println("\t" + "Capacitance: " + capacitance);
		System.out.println("\t" + "inductance: " + inductance);
	}
	
	
}

