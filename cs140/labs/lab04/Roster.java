package lab04;

import java.util.ArrayList;

public class Roster {
	private ArrayList <Student> classRoster = new ArrayList<>();

	public ArrayList <Student> getRoster()
	{
		return classRoster;
	}
	
	public void addStudent(Student s)
	{
		classRoster.add(s);
	}
	
	public void dropStudent(String name)
	{
		
		for (int i = 0; i < classRoster.size(); i++)
		{
			if (classRoster.get(i).getName() == name)
				classRoster.remove(i);
		}
	}
	
	public String toString()
	{
		String returnVal = new String ("[");
		for (int i= 0; i <classRoster.size(); i++)
		{
			if(i < classRoster.size()-1)
				returnVal += (classRoster.get(i).getName()) + ", ";
		
			else 
				returnVal += (classRoster.get(i).getName()) + "]";

		}
		return returnVal;
	}
	
	public void sortById()
	{
		for(int i = 0; i < classRoster.size(); i++){
		      for(int j = 1; j < (classRoster.size() - i); j++){
		           if(classRoster.get(j-1).getId() > classRoster.get(j).getId())
		           {
		               //swap elements
		              Student temp = classRoster.get(j-1);
		              classRoster.set(j-1, classRoster.get(j));
		              classRoster.set(j, temp);
		           }
	
	
		      }
		}
	}
	
}
