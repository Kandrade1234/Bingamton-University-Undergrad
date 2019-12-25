package assignment05;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
public class Test {
	public static void main(String args[]){
   

	TravelExpenses planeExpense = new TravelByAir(LocalDate.of(2017, 10, 25), LocalDate.of(2017, 10, 26), "Delta Air Lines", 355.00);
	TravelExpenses lodging = new Lodging(LocalDate.of(2017, 11, 25), LocalDate.of(2017, 11, 26), "Cabin in the Woods", 365.00);
	TravelExpenses meals = new Meal(MealType.LUNCH, 12.50, LocalDate.of(2017, 11, 27));
	TravelExpenses busExpense = new TravelByBus(LocalDate.of(2017, 10, 28), LocalDate.of(2017, 10, 29), "Bee Line", 50);
	TravelExpenses ownCar = new TravelByOwnCar(LocalDate.of(2017, 12, 20), LocalDate.of(2017, 12, 25));
	TravelExpenses byRail = new TravelByRail(LocalDate.of(2017, 10, 28), LocalDate.of(2017, 10, 29),"Metro north", 200.00);
	TravelExpenses rentalCar = new TravelByRentalCar(300, "Entreprise auto",LocalDate.of(2017, 10, 28), LocalDate.of(2017, 10, 29));
	ArrayList <TravelExpenses> expen = new ArrayList <TravelExpenses>(Arrays.asList(planeExpense, lodging, meals,busExpense,ownCar,byRail,rentalCar));
	

	for(int i =0; i < expen.size(); i++ ){
			if(expen.get(i) instanceof TravelByOwnCar)
				((TravelByOwnCar) expen.get(i)).addMiles(200);
			
			if(expen.get(i) instanceof TravelByRentalCar)
				((TravelByRentalCar) expen.get(i)).addFuel(60.75, 120.00);
			System.out.println(expen.get(i).amountToReimburse());
	}
	
	TravelExpenses.printReport(expen);
	
	/////////////////////////////////////////////////////TEST 2////////////////////////////////////////
	
	System.out.println("------------------");
	NamesResource a = new NamesResource();
	NamesResource b = new NamesResource();
	NamesResource c = new NamesResource();
	NamesResource d = new NamesResource();
	NamesResource e = new NamesResource();
	ByCourseProgress uno = new ByCourseProgress();
		Person one = new Person(a.getRandomLastName(), a.getRandomFirstName(), LocalDate.of(2016, 10, 25));
		Person two = new Person(b.getRandomLastName(), b.getRandomFirstName(),LocalDate.of(2017, 10, 25));
		Person three = new Person(c.getRandomLastName(), c.getRandomFirstName(), c.getRandomBirthDate(2017));
		Person four = new Person(d.getRandomLastName(), d.getRandomFirstName(), d.getRandomBirthDate(2017));
		Person five = new Person(e.getRandomLastName(), e.getRandomFirstName(), e.getRandomBirthDate(2017));

		Student first = new Student(one);
		Student second = new Student (two);
		Student third = new Student (three);
		Student fourth = new Student (four);
		Student fifth = new Student (five);
		
		
		Course Math = new Course("Math");
		Math.setNumReadings(2);
		Math.setPages(0, 23);
		Math.setPages(1, 24);

		Course Hist = new Course("History");
		Hist.setNumReadings(3);
		Hist.setPages(0, 33);
		Hist.setPages(1, 44);
		Hist.setPages(2, 15);

		Course Eng = new Course("English");
		Eng.setNumReadings(1);
		Eng.setPages(0, 43);
		
		Course Sci = new Course ("Science");
		Sci.setNumReadings(2);
		Sci.setPages(0, 23);
		Sci.setPages(1, 24);

		Course Art = new Course("Art");
		Art.setNumReadings(1);
		Art.setPages(0, 23);
//////////////////////////////////////////////
		//First Student
		System.out.println(first.getPerson() + "\n" );
		first.setCourse(Math);
		for(int i =0; i < Math.getTotalPages(0); i++)
			first.read(0);
		System.out.println("Only the first reading performed fully (percentage read): " + first.percentRead());
		System.out.println("Only the first reading completed (completion percentage): " + first.percentCompleted());
		
		for(int i =0; i < Math.getTotalPages(1); i++)
			first.read(1);
		
		System.out.println("All readings done(percentage read): " + first.percentRead());
		System.out.println("All readings completed (completion percentage):  " + first.percentCompleted());
////////////////////////////////////////
		//Second Student
		System.out.println("\n" + second.getPerson() + "\n " );

		second.setCourse(Hist);
		for(int i =0; i < Hist.getTotalPages(0); i++)
			second.read(0);
		System.out.println("Only the first reading performed fully (percentage read): " + second.percentRead());
		System.out.println("Only the first reading completed (completion percentage): " + second.percentCompleted());
		
		for(int i =0; i < Hist.getTotalPages(1); i++)
			second.read(1);
		
		System.out.println("All readings done(percentage read): " + second.percentRead());
		System.out.println("All readings completed (completion percentage):  " + second.percentCompleted());
		
		
		for(int i =0; i < Hist.getTotalPages(2); i++)
			second.read(2);
		System.out.println("All readings done(percentage read): " + second.percentRead());
		System.out.println("All readings completed (completion percentage):  " + second.percentCompleted());
		


		
////////////////////////////////////////
//Third Student		
		System.out.println("\n" + third.getPerson() + "\n " );
		third.setCourse(Eng);
		
		for(int i =0; i < Eng.getTotalPages(0); i++)
			third.read(0);
		System.out.println("Only the first reading performed fully (percentage read): " + third.percentRead());
		System.out.println("Only the first reading completed (completion percentage): " + third.percentCompleted());
		
		//COMPARATOR
		System.out.print(" \nExpected negative integer:" +uno.compare(fourth, third));

////////////////////////////////////////
//Fourth Student
		
		System.out.println("\n" + fourth.getPerson() + "\n " );
		fourth.setCourse(Sci);
		
		for(int i =0; i < Sci.getTotalPages(0); i++)
			fourth.read(0);
		System.out.println("Only the first reading performed fully (percentage read): " + fourth.percentRead());
		System.out.println("Only the first reading completed (completion percentage): " + fourth.percentCompleted());
	
		//COMPARATOR
		System.out.print(" \nExpected positive integer:" +uno.compare(third, fourth) + "\n");
		for(int i =0; i < Hist.getTotalPages(1); i++)
			fourth.read(1);
		
		System.out.println("All readings done(percentage read): " + fourth.percentRead());
		System.out.println("All readings completed (completion percentage):  " + fourth.percentCompleted());
		
////////////////////////////////////////
//Fifth Student		
		System.out.println("\n" + fifth.getPerson() + "\n " );
		fifth.setCourse(Art);
		
		for(int i =0; i < Art.getTotalPages(0); i++)
			fifth.read(0);
		System.out.println("Only the first reading performed fully (percentage read): " + fifth.percentRead());
		System.out.println("Only the first reading completed (completion percentage): " + fifth.percentCompleted());
		

//////////////////// MORE Comparing///////////////////////
		NamesResource testD = new NamesResource();
		
		Person testd = new Person(testD.getRandomLastName(), testD.getRandomFirstName(), LocalDate.of(2017, 10, 25));
		
		Student testDummy1 = new Student(testd);
		Student testDummy2 = new Student(testd);

		System.out.print("\nExpected postive output: " + uno.compare(first, testDummy1));
		System.out.print("\nExpected negative output: " + uno.compare(testDummy1, first));
		System.out.print("\nExpected zero output: " + uno.compare(testDummy1, testDummy2));

		
		Course test = new Course("CS");
		
		test.setNumReadings(1);
		test.setPages(0, 10);
		testDummy1.setCourse(test);
		for(int i =0; i < test.getTotalPages(0); i++){
			testDummy1.read(0);
		}
		
		Course test2 = new Course("ES");
		test2.setNumReadings(2);
		test2.setPages(0, 10);
		test2.setPages(1, 10);
		testDummy2.setCourse(test2);
		for (int i = 0; i < test2.getTotalPages(0); i++)
			testDummy2.read(0);
		System.out.print(" \nExpected positive integer: " +uno.compare(testDummy1, testDummy2) );
		System.out.print(" \nExpected negative integer: " +uno.compare( testDummy2, testDummy1) + "\n");

		ByDobThenNameComp testing = new ByDobThenNameComp ();
		System.out.println("Expected positive integer: " + testing.compare(testd, one));
		System.out.println("Expected negative integer: " + testing.compare( one, testd));
		System.out.println("Because of equal birthdays and random name generator, it will range from positive and negative integers each time it is compiled: " + testing.compare(testd, two));
		
	
	
	
	}
	
}
