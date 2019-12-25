package assignment04;

public class Employee 
{
	private Person person; 
	private double salary;
	
	public Employee(Person input)
	{
		person = input;
	}
	public void setSalary(double sal)
	{
		this.salary = sal;
	}

	public String toString()
	{
		StringBuilder build = new StringBuilder();
		build.append(person.getFirstName());
		build.append(" ");
		build.append(person.getMiddleInitial());
		build.append(". ");
		build.append(person.getLastName());
		build.append(", ");
		build.append("salary: $");
		build.append(salary);
		
		return build.toString();
	//	return person.getFirstName() + " " + person.getMiddleInitial() + ". " + person.getLastName()+ ": " + salary;
	}
	
	
	
	
	
}
