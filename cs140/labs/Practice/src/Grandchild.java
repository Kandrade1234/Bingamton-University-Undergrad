public class Grandchild extends Child {
	private int var3;
	public Grandchild (int x, int y, int z) {
		super(x, y);
		this.var3 = z;
	}
	public int method2() {
		return method1() - var3;
	}
}