package assignment05;

public class Student {

	private Person self;
	private Course course;
	private int[] progress;
	private boolean[] completed;
	
	public Student(Person self){
		this.self = self;
	}
	
	
	public Person getPerson(){
		return self;
	}
	
	public Course getCourse(){
		return course;
	}
	
	public void setCourse(Course crs)
	{
		course = crs;
		progress = new int[course.getNumReadings()];
		completed = new boolean [course.getNumReadings()];	
		for(int i =0; i < completed.length; i++){
			completed[i] = false;
		}
	}
	
	public void read(int reading){
		if(completed[reading]){
			return;}
		
		progress[reading] += 1;
		if(progress[reading] == course.getTotalPages(reading))
			completed[reading] = true;
	
	}
	
	public int percentRead()
	{
		///????
		int totalPagesRead = 0;
		int totalPagesOfReadingRead = 0;
		for (int i=0; i< progress.length; i++){
			totalPagesRead += progress[i];
			totalPagesOfReadingRead += course.getTotalPages(i);
		}
		
		double totalPagesR = (double) (totalPagesRead);
		double totalPagesOfR = (double) (totalPagesOfReadingRead);
		totalPagesR = totalPagesR * 100;

		
		
		return (int)Math.round(totalPagesR) / (int)Math.round(totalPagesOfR);
		
		
		
	}
	
	public int percentCompleted(){
		int compl = 0;
		for(int i =0; i < completed.length; i++){
				if(completed[i])
					compl += 1;
		}
		double read = (double) (compl);
		double totalReadings = (double) course.getNumReadings();
		read = read * 100;
		//return (int) Math.round(totalReadings) / (int) Math.round(read);
		return (int)Math.round(read) / (int) totalReadings;
	}
	
	
}
