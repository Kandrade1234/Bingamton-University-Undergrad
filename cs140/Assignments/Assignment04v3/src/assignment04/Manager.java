package assignment04;
import java.util.ArrayList;
public class Manager extends Employee {
	private String department;
	private ArrayList<Employee> team = new ArrayList<Employee>();

	
	
	public Manager(Person p)
	{
		super(p);
	}
	
	public void addToTeam(Employee input){
		team.add(input);
	}
	
	public void setDepartment(String department)
	{
		this.department = department; 
	}
	
	
	public String toString()
	{
		StringBuilder build = new StringBuilder();
		build.append(super.toString());
		build.append("\n");
		build.append(department);
		build.append("\n");

		
		for(int i = 0; i < team.size(); i++)
			{
			build.append("\t");
			build.append(team.get(i).toString());
			build.append("\n");
			}
		return build.toString();
	}
	
}
