package shapes;

public class rectangle extends Shapes
{
	public rectangle (int x, int y, int z, String a)
	{
		super(x, y, z, a);
	}
	
	private int area = 0;
	public int area ()
	{
		area = super.getLength() * super.getWidth();
		return area;
	}
	
	public void display()
	{
		System.out.println(super.getName());
		System.out.println(area());
	}
	
}
