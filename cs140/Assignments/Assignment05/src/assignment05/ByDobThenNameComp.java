package assignment05;

import java.util.Comparator;

public class ByDobThenNameComp implements Comparator<Person> {

	public int compare(Person person1, Person person2){
		if(person1.getdateOfBirth().compareTo(person2.getdateOfBirth())==0){
			return person1.compareTo(person2);
		}
		return person1.getdateOfBirth().compareTo(person2.getdateOfBirth());
		
	}
}
