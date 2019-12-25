package Ques4;

public class Question4 {
	public static int function(int a, int b) {
		if(b == 0) throw new ArithmeticException("bad input");
		if(b < 0) return function(a, -b);
		if(a < 0) return -function(-a, b);
		if(a < b)
			return a;
		else
			return function(a - b, b);
	}
	public static void main(String[] args) {
		System.out.println(function(25, 6));
		System.out.println(function(-23, 6));
	}
}