package assignment01;

public class Person {
	
	/** Private data members*/
	private String lastName;
	private String firstName; 
	private char middleInitial;

		
	/** Constructor */
	public Person (String aLastName, String aFirstName, char aMiddleInitial)
	{
		lastName = aLastName;
		firstName = aFirstName;
		middleInitial = aMiddleInitial;
	}
	
	
	/**Accesors/Getter functions*/
	public String getLastName()
	{
		return lastName; 
	}
	
	public String getFirstName()
	{
		return firstName; 
	}
	
	public char getMiddleInitial()
	{
		return middleInitial; 
	}
	
}
