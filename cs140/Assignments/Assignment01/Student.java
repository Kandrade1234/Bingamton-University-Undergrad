package assignment01;

public class Student {

	/**Private data members*/
	private Person self; 
	private Class class1 = Class.DUMMY_CLASS;
	private Class class2 = Class.DUMMY_CLASS;
	private Class class3 = Class.DUMMY_CLASS;
	private Class class4 = Class.DUMMY_CLASS;

	
	
	/**Setters for quality points*/
	public void setQualPoints1(double qPoints)
	{
		class1.setQualPoints(qPoints);
	}
	
	public void setQualPoints2(double qPoints)
	{
		class2.setQualPoints(qPoints);
	}
	
	public void setQualPoints3(double qPoints)
	{
		class3.setQualPoints(qPoints);
	}

	public void setQualPoints4(double qPoints)
	{
		class4.setQualPoints(qPoints);
	}

	
	/**Accesor/Getter function*/
	public String getName()
	{
		return self.getFirstName() + " " + self.getMiddleInitial() + ". " +  self.getLastName();
	}
	
	/**Constructor*/
	public Student (Person aSelf)
	{
		self = aSelf; 
	}
	

	
	/**Accesors/Getters for Class1*/
	public Class getClass1()
	{
		return class1;	
	}
	
	public Class getClass2()
	{
		return class2;	
	}
	public Class getClass3()
	{
		return class3;	
	}
	public Class getClass4()
	{
		return class4;	
	}

	public void setClass1(Class Input)
	{	
		 class1 = Input;
	}
	public void setClass2(Class Input)
	{	
		 class2 = Input;
	}
	public void setClass3(Class Input)
	{	
		 class3 = Input;
	}
	public void setClass4(Class Input)
	{	
		 class4 = Input;
	}
	
	/**Computes gpa  by checking if the total amount of credits is higher then zero; if true, then 
	 * divide the total quality points  by the amount of credits they have for that semester. 
	 */
	public double computeSemesterGPA(){
		double gpa = 0.0d;
		double totalPoints= 0.0d;
		int totalCredits = 0;
		totalPoints =  class1.getQualPoints() + class2.getQualPoints() + class3.getQualPoints() + class4.getQualPoints(); 
		totalCredits = class1.getNumCredits() + class2.getNumCredits() + class3.getNumCredits() + class4.getNumCredits();
		if (totalCredits > 0)
			gpa = totalPoints / totalCredits;
		return gpa; 
	}
}
