package assignment05;

import java.time.LocalDate;

public class Person implements Comparable <Person> {

	private String lastName;
	private String firstNames;
	private LocalDate dateOfBirth;
	
	public Person(String last, String first, LocalDate birth){
		lastName = last;
		firstNames = first;
		dateOfBirth = birth;
	}
	
	public int compareTo(Person other){
		return (lastName + firstNames).compareToIgnoreCase(other.lastName + other.firstNames);

	}
	
	public LocalDate getdateOfBirth(){
		return dateOfBirth;
	}
	
}
