public class Driver {
	public static void main(String[] args) {
		Top t = new Top();
		t.test(1);
		t = new Middle();
		t.test(2);
		t = new Bottom();
		t.test(3);
	}
}