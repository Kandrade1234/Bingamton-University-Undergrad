public class Parent {
	private int var1;
	public Parent (int x) {
		var1 = x;
	}
	public int method1() {
		var1 = 2 + var1;
		return var1;
	}
	public int method2() {
		var1 = var1 - 1;
		return var1;
	}
	public int test() {
		return method1() + method2();
	}
}