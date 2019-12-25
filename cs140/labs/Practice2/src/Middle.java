public class Middle extends Top {
	private int b = -1;
	@Override
	public int method1(int i) {
		setA(method2(3));
		return i + b;
	}
	@Override
	public int method2(int i) {
		return 2*i + b;
	}

}


