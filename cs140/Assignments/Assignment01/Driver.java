package assignment01;

public class Driver {

	public static void main(String[] args) {
		/**Creates three objects of type Person*/
		Person one = new Person (	"Andrade" , "Kevin", 'A');
		Person two = new Person ("Uruchima", "Nathaly", 'D');
		Person three = new Person ("Mendez", "Emily", 'U');
		
		/**Creates three objects of type Student*/
		Student sOne = new Student (one);
		Student sTwo = new Student (two);
		Student sThree = new Student (three);
		
		
		
		Class class1 = new Class ("Programing With Objects", "CS 140", 4, 10390);
		Class class2 = new Class ("Linear Algebra", "Math 304", 4, 23423);
		Class class3 = new Class ("Ethical Social & Global Issues Computing", "CS 301", 4, 24317);
		
		Class class4 = new Class ("Wellness Thru Weight Training", "HWS 215", 2, 21788);
		Class class5 = new Class ("Professional Skills Ethics & CS Trends", "cs 101", 1, 10039);
		Class class6 = new Class ("Lab In Genral Psychology", "PSYC 112", 1, 11272);
		Class class7 = new Class ("Intro to Anthropology", "ANTH 111", 4, 10042);
		
	
		sTwo.setClass1(class1);
		sTwo.setClass2(class2);
		sTwo.setClass3(class3);
		
		
		sThree.setClass1(class4);
		sThree.setClass2(class5);
		sThree.setClass3(class6);
		sThree.setClass4(class7); 
		
		
		/**Calls the setQualPoints function. This function will set the points they recieved for 
		 * the class. Ex: Student recieves an A in the course, that would be a 4.00 in the course
		 * which then gets multiply by the amount of credits the course was worth for and that equals 
		 * the amount of quality points they recieved for the class.
		 */
		sTwo.setQualPoints1(4.00 * sTwo.getClass1().getNumCredits());
		sTwo.setQualPoints2(3.70 * sTwo.getClass2().getNumCredits());
		sTwo.setQualPoints3(3.30 * sTwo.getClass3().getNumCredits());
		
		
		
		sThree.setQualPoints1(4.00 * sThree.getClass1().getNumCredits());
		sThree.setQualPoints2(3.70 * sThree.getClass2().getNumCredits());
		sThree.setQualPoints3(3.30 * sThree.getClass3().getNumCredits());
		sThree.setQualPoints4(3.00 * sThree.getClass4().getNumCredits());
		
		/**This will print out the total semester gpa of the current student. It uses the 
		 * computeSemesterGpa function which will calculate your gpa.
		 */
		System.out.print("Student: ");
		System.out.print(sTwo.getName());
		System.out.printf("\nGPA: %.3f\n", sTwo.computeSemesterGPA());
		System.out.print("Expected GPA: 3.667\n\n");
		
		System.out.print("Student: ");
		System.out.print(sThree.getName());
		System.out.printf("\nGPA: %.3f\n", sThree.computeSemesterGPA());
		System.out.print("Expected GPA is 3.375");
		
	}

}
