package shapes;

public class main 
{
	public static void main (String[] arg)
	{
		rectangle recObject = new rectangle( 5, 4,  3,  "rectangle");
		System.out.println(recObject.getLength());
		System.out.println(recObject.getWidth());
		System.out.println(recObject.area());
		
		recObject.display();
	}
}
