package lab04;

public class RosterTester {

	public static void main (String[] args)
{
	Roster rost = new Roster ();
	
	Student student1 = new Student (123, "Chris");
	Student student2 = new Student (893, "Lesly");
	Student student3 = new Student (311, "John");
	Student student4 = new Student (421, "Peter");
	Student student5 = new Student (684, "Joe");
	Student student6 = new Student (111, "Kevin");

	
	rost.addStudent(student1);
	rost.addStudent(student2);
	rost.addStudent(student3);
	rost.addStudent(student4);
	rost.addStudent(student5);
	rost.addStudent(student6);

	
	System.out.print("Current Roster: ");
	System.out.println(rost.toString());
	
	System.out.print("Sorted Roster: ");
	rost.sortById();
	System.out.println(rost.toString());
	
	System.out.println("We will drop two students......");
	rost.dropStudent("John");
	rost.dropStudent("Chris");
	System.out.print("Current Roster: ");
	System.out.println(rost.toString());

	System.out.println("\nHere is the Current Dean's List: " + "\t  ID:");
	for (int i=0; i < rost.getRoster().size(); i++)
	{
		System.out.println(rost.getRoster().get(i).getName()+ "\t\t\t\t\t  " + rost.getRoster().get(i).getId());
		
	}

	
	


	
}
	
	
	
	
	
}
