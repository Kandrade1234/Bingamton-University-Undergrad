
public class Top {
	private int a = 2;
	public void test (int i) {
		int k = method1(i) + method2(a);
		System.out.println(k);
	}
	public int method1(int i) {
		return i + 1;
	}
	public int method2(int i) {
		return i + 2;
	}
	public void setA(int i) {
		a = i;
	}
}