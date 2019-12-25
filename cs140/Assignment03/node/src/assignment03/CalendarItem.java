package assignment03;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
public class CalendarItem {

	private LocalDateTime start;
	private LocalDateTime end;
	private String title;
	private String description;
	private String location;
	private CalendarItem nextItem;
	
	public String getTitle(){
		return title;
	}
	public void setTitle(String input){
		title = input;
	}

	public String getDescription(){
		return description;
	}
	public void setDescription(String input){
		description = input;
	}
	
	public String getLocation(){
		return location;
	}
	public void setLocation(String input){
		location = input;
	}
	
	public CalendarItem getNextItem(){
		return nextItem;
	}
	public void setNextItem(CalendarItem input){
		nextItem = input;
	}
	
	public void setEnd(LocalDateTime end){
		if(start != null && start.isAfter(end))
			throw new IllegalArgumentException("the start cannot be after end");
		else
			this.end = end; 
	
	}
	public LocalDateTime getEnd(){
		return end;
	}
	
	
	public void setStart(LocalDateTime start){
		if(end != null && end.isBefore(start))
			throw new IllegalArgumentException("the end cannot be before the start");
		else 
			this.start = start;
	
	}
	
	public LocalDateTime getStart()
	{
		return start;
	}
	public String toString() {
		DateTimeFormatter dayForm =  DateTimeFormatter.ofPattern("MMMM d, yyyy");
		DateTimeFormatter timeForm =  DateTimeFormatter.ofPattern("h:m a");
		if(start.getDayOfYear() == end.getDayOfYear() )
		{
		return start.format(dayForm) +" from " + start.format(timeForm) 
				+ " to " + end.format(timeForm) + "\n"
				+ title + " in " + location + "\n"
				+ description;
		}
		return start.format(dayForm) +" from " + start.format(timeForm) 
		+ " to "+ end.format(dayForm)+ " " + end.format(timeForm) + "\n"
		+ title + " in " + location + "\n"
		+ description;
	}
	public boolean endsBefore(CalendarItem other){
		return end.isBefore(other.start);
	
	}
	public boolean startsAfter(CalendarItem other)
	{
		return start.isAfter(other.end);
	}
	
	public boolean noTimeConflictWith(CalendarItem other) {
		return endsBefore(other) || startsAfter(other);
	}	
	
	public boolean hasTimeConflictWith(CalendarItem other) {
		return !noTimeConflictWith(other);
	}
	
	
	
	
	
	
	
	public static void main(String[] args) {
		CalendarItem test = new CalendarItem();
		test.setDescription("this is just a sample meeting of CS 140");
		test.setEnd(LocalDateTime.of(2017,9,11,11,50));
		test.setStart(LocalDateTime.of(2017,9,11,10,50));
		test.setTitle("CS 140");
		test.setLocation("FA 212");
		
		System.out.println(test + "\n");
		
		
	
		CalendarItem test2 = new CalendarItem();
		test2.setDescription("this is just a sample meeting of CS 301");
		test2.setEnd(LocalDateTime.of(2017,9,13,11,50));
		test2.setStart(LocalDateTime.of(2017,9,12,10,50));
		test2.setTitle("CS 301");
		test2.setLocation("NB 22");
		System.out.println(test2);
		
		if(test.noTimeConflictWith(test2))
			System.out.println("\nExpected: No conflict in scheduling \t" + "Result: No conflict in scheduling");
		
		
		CalendarItem test3 = new CalendarItem();
		test3.setDescription("this is just a sample meeting of CS 240");
		test3.setEnd(LocalDateTime.of(2017,9,13,11,50));
		test3.setStart(LocalDateTime.of(2017,9,12,10,50));
		test3.setTitle("CS 240");
		test3.setLocation("FA 122");
		
		if(test2.hasTimeConflictWith(test3))
			System.out.println("Expected: Conflict in scheduling \t" + "Result: Conflict in scheduling");

		
		
		
		
		
		
	}
	
	
	
	
}
