package assignment05;

public class Course {

	private String courseName;
	private int[] pagesToRead;
	
	
	public Course(String name){
		courseName = name;
	}
	public void setNumReadings(int readings){
		pagesToRead = new int[readings];
	}
	
	public void setPages(int reading, int totalPages){
		pagesToRead[reading] = totalPages;
	}
	
	public int getNumReadings(){
		return pagesToRead.length;
	}
	
	public int getTotalPages(int reading){
		return pagesToRead[reading];
	}
	
	public String getCourseName(){
		return courseName;
	}
}
