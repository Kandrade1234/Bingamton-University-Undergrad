public class Child extends Parent {
	private int var2;
	public Child (int x, int y) {
		super(x);
		var2 = y;
	}
	public int method1() {
		var2 = super.method1() - var2;
		return var2;
	}
}