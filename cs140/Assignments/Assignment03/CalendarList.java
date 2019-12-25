package assignment03;
import java.time.LocalDateTime;
import java.util.Optional;

public class CalendarList {
    private CalendarItem first;
    private CalendarItem next;

    public void setNext()
    {   CalendarItem nowObject = new CalendarItem();    
        nowObject.setEnd(LocalDateTime.now());

       nowObject.setStart(LocalDateTime.now());
        
       LocalDateTime now = LocalDateTime.now();
       CalendarItem temp = first;
    	while(temp != null && (temp.getEnd().isEqual(now) || temp.getEnd().isBefore(now)) )
    	{
    		if(temp.getNextItem() == null)
    		{
    			next = temp;
    			break;
    		}
    		temp = temp.getNextItem();
	
    		
    	}
    	
    }
    

    public void resetFirst()
    {
    	this.setNext();
    	first = next;
    
    	
    }
    
    
    
    private void insert(CalendarItem newItem)
    {
    	if(first == null)
    	{	first = newItem;
    		return;
    	}
    	else if(newItem.endsBefore(first))
    	{
    		newItem.setNextItem(first);
    		first = newItem;
    		return;
    	}
    	else 
    	{
    		CalendarItem temp= first;
    		while (temp.getNextItem()!= null)
    		{
    			if (newItem.endsBefore(temp.getNextItem()))
    			{
    				newItem.setNextItem(temp.getNextItem());
    	    		temp.setNextItem(newItem);
    				return;
    			}
    			temp = temp.getNextItem();
    		}
    		temp.setNextItem(newItem);
    	//	newItem = temp;
    	}
    		
    		
    }
    
    public Optional<CalendarItem> findConflict(CalendarItem newItem)
    {
    	
    	
    	if (first == null)
    		return Optional.empty();
    	
    	
    	CalendarItem temp = first;
    	
    	while (temp!= null)
    	{
    		
    		if(temp.hasTimeConflictWith(newItem))
    			return Optional.of(newItem);
    		temp = temp.getNextItem();
    	}
		return Optional.empty();

    }
    public void insertItem(CalendarItem newItem)
    {   
    	CalendarItem nowObject = new CalendarItem();    
    	 nowObject.setStart(LocalDateTime.now());
         nowObject.setEnd(LocalDateTime.now());
  
    	if (first != null)
    	{
    		this.setNext();
    		if(newItem.endsBefore(nowObject))
    		{
    			throw new IllegalArgumentException("It is to late for that appointment");
    		}
    		if(newItem.getStart().isBefore(LocalDateTime.now()))
    		{
    			throw new IllegalArgumentException("That appointment is under way--run!");

    		}
    			Optional <CalendarItem> temp = findConflict(newItem);
    		if(temp.isPresent()) {
    			throw new IllegalArgumentException("You have a conflict. "
    			+ "Please use findConflict to find the conflicting appointment");
    		}
    	}
    	this.insert(newItem);
    	
    	
    	
    }
    
    void testingInsert(CalendarItem newItem)
    {
  
    	if (first != null)
    	{
    		this.setNext();
    			Optional <CalendarItem> temp = findConflict(newItem);
    		if(temp.isPresent()) {
    			throw new IllegalArgumentException("You have a conflict. "
    			+ "Please use findConflict to find the conflicting appointment");
    		}
    	}
    	this.insert(newItem);
    	
    	
    	
    }
    public void printNext()
    {
    	System.out.println(next);
    }
    

    public void printCalendar()
    {
    	CalendarItem temp = first;
    	while (temp!= null)
    	{
    		System.out.println(temp);
    		temp = temp.getNextItem();
    		
    		
    	}
    	
    	
    	
    }
    
	public static void main(String[] args) {
	
		CalendarList testing = new CalendarList();
		CalendarItem ev1 = new CalendarItem();
		ev1.setDescription("this is just a sample meeting of CS 301");
		ev1.setEnd(LocalDateTime.of(2017,9,13,11,50));
		ev1.setStart(LocalDateTime.of(2017,9,12,10,50));
		ev1.setTitle("CS 301");
		ev1.setLocation("NB 22");
		
		
		CalendarItem ev2 = new CalendarItem();
		ev2.setDescription("this is just a sample meeting of CS 240");
		ev2.setEnd(LocalDateTime.of(2017,11,24,11,50));
		ev2.setStart(LocalDateTime.of(2017,11,24,10,50));
		ev2.setTitle("CS 240");
		ev2.setLocation("FA 122");

		
		CalendarItem ev3 = new CalendarItem();
		ev3.setDescription("this is just a sample meeting of CS 140");
		ev3.setEnd(LocalDateTime.of(2017,9,25,11,50));
		ev3.setStart(LocalDateTime.of(2017,9,25,10,50));
		ev3.setTitle("CS 140");
		ev3.setLocation("FA 212");
		
		CalendarItem conflict = new CalendarItem();
		conflict.setDescription("this is just a sample meeting of CS 340");
		conflict.setEnd(LocalDateTime.of(2017,9,13,11,55));
		conflict.setStart(LocalDateTime.of(2017,9,13,7,50));
		conflict.setTitle("CS 340");
		conflict.setLocation("FA 212");
		System.out.println("Testing if we can set an appointment before another appointment.....\n");
		

		//Inserting
		testing.insertItem(ev1);
		testing.insertItem(ev2);
		
		
		
		//Testing Exceptions
		try {	
		
		testing.insertItem(ev3);
		
		} catch (IllegalArgumentException e)
						{
							System.out.println(e);
						}
				
	
	
	System.out.println("\nPrinting current appointment list.... \n");
	testing.printCalendar();	
	
	System.out.println("\nTesting to see if there is a conflict trying to add an event before the others.... \n");
	
	//Testing optional
	Optional<CalendarItem> test = testing.findConflict(conflict);	
	//System.out.println(testing.findConflict(conflict));
	
	if(test.isPresent())
	{
		
		System.out.println("There is a conflict trying to add the calnedarItem: \n" + test.get());
	}
	
	System.out.println("\nPrinting new appointment list.... \n");

	CalendarItem evN1 = new CalendarItem();
	evN1.setDescription("this is just a sample meeting of CS 120");
	evN1.setEnd(LocalDateTime.of(2015,9,13,11,50));
	evN1.setStart(LocalDateTime.of(2015,9,12,10,50));
	evN1.setTitle("CS 120");
	evN1.setLocation("NB 22");

	CalendarItem evN2 = new CalendarItem();
	evN2.setDescription("this is just a sample meeting of CS 440");
	evN2.setEnd(LocalDateTime.of(2015,11,24,11,50));
	evN2.setStart(LocalDateTime.of(2015,11,24,10,50));
	evN2.setTitle("CS 440");
	evN2.setLocation("FA 123");
	
	
	CalendarItem evN3 = new CalendarItem();
	evN3.setDescription("this is just a sample meeting of CS 540");
	evN3.setEnd(LocalDateTime.of(2015,9,25,11,50));
	evN3.setStart(LocalDateTime.of(2015,9,25,10,50));
	evN3.setTitle("CS 540");
	evN3.setLocation("FA 213");
	
	
	
	
	
	testing.testingInsert(evN1);
	testing.testingInsert(evN2);
	testing.testingInsert(evN3);

	testing.printCalendar();

	
	System.out.println("\nPrinting updated appointment list.... \n");

	testing.resetFirst();
	testing.printCalendar();


	}
		
		
		
		
	
    
    
    
}