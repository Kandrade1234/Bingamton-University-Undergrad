package assignment01;
public class Class {
	
	/**Private data field*/
	private String name; 
	private String number;
	private int crn;
	private int numCredits;
	private double qualPoints; 
	
	/**Constructor*/
	public Class(String aName, String aNumber, int aNumCredits, int aCrn){
		name = aName; 
		number = aNumber;
		numCredits = aNumCredits;
		crn = aCrn; 
		}	
    
	
	public static final Class DUMMY_CLASS = new Class ("Dummy", "000",0, 0);

	//*Getter functions*/
	public String getName() {
		return name; 
	}
	
	public String getNumber()
	{
		return number;
	}
	
	public int getCrn()
	{
		return crn;
	}
	
	public int getNumCredits() {
		return numCredits;
	}
	
	public double getQualPoints()
	{
		return qualPoints; 
	}
	
	/** Setter functions*/
	public void setQualPoints(double qPoints){
	     qualPoints = qPoints;
	}
	
}
