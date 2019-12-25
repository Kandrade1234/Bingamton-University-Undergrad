package lab04;

public class Student {

	private int id;
	private String name;
	
	public Student (int idNum, String nameInput)
	{
		id = idNum;
		name = nameInput;
	}
	
	
	public int getId()
	{
		return id;
	}
	
	public String getName()
	{
		return name;
	}

}
