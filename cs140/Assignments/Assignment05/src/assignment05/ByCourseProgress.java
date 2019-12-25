package assignment05;

import java.util.Comparator;

public class ByCourseProgress implements Comparator <Student> {
	
	public int compare(Student a, Student b){
		if(a.getCourse() == null && b.getCourse() != null)
			return -1;
		if(a.getCourse() != null && b.getCourse() == null){
			return 1;
		}
		if(a.getCourse() == null && b.getCourse() == null){
			return a.getPerson().compareTo(b.getPerson());
		}
		if(a.percentRead() > b.percentRead())
			return 1;
		if (a.percentRead() < b.percentRead())
			return -1;
		if(a.percentCompleted() > b.percentCompleted())
			return 1;
		if(a.percentCompleted() < b.percentCompleted()){
			return -1;
		}
		return a.getPerson().compareTo(b.getPerson());
		
	}	
}
