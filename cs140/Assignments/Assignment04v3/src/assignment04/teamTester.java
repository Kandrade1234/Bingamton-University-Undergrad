package assignment04;

public class teamTester {

	public static void main (String args[])
	{
		//Manager
		Person mJohn = new Person ("Ronald" , "John", 'C');
		Person mSteven = new Person ("Lander" , "Steven", 'K');

		//People(team)
		Person kevin = new Person ("Andrade" , "Kevin", 'A');
		Employee kev = new Employee (kevin);
		kev.setSalary(75000.00);
		Person nathaly = new Person ("Uruchima" , "Nathaly", 'D');
		Employee nat = new Employee(nathaly);
		nat.setSalary(70000.00);
		Person chris = new Person ("Lavender" , "Chris", 'X');
		Employee chr = new Employee (chris);
		chr.setSalary(65000.00);


		Person spongebob = new Person ("Square" , "Spongebob", 'P');
		Employee sponge = new Employee (spongebob);
		sponge.setSalary(15000.00);

		Person Alex = new Person ("Lamb" , "Alexander", 'F');
		Employee Al = new Employee (Alex);
		Al.setSalary(45000.00);

		
		
		Manager John = new Manager (mJohn);
		John.setDepartment("Computers");
		John.setSalary(150000);
		Manager Steven = new Manager (mSteven);
		Steven.setSalary(200000);
		Steven.setDepartment("Home theater");
		
		
		
		John.addToTeam(kev);
		John.addToTeam(nat);
		John.addToTeam(chr);
		
		
		Steven.addToTeam(sponge);
		Steven.addToTeam(Al);

		System.out.println(John.toString());
		System.out.println(Steven.toString());
		
		
		
	}
	
	
}
