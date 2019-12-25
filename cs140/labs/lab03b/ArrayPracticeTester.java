package lab03;
import java.util.Arrays;
import static lab03.ArrayPractice.*;
public class ArrayPracticeTester {
	public static void test(String expected, int[] actual) {
	    System.out.println("Expected: " + expected +
	                       ", received: " + Arrays.toString(actual));
	}

	public static void test(int[] expected, int[] actual) {
	    System.out.println("Expected: " + Arrays.toString(expected) +
	                       ", received: " + Arrays.toString(actual));
	}

	public static void test(boolean expected, boolean actual) {
	    System.out.println("Expected: " + expected + ", received: " + actual);
	}
	public static void test(String expected, boolean actual) {
	    System.out.println("Expected: " + expected + ", received: " + actual);
	}
	public static void test(String expected, double actual) {
	    System.out.println("Expected: " + expected + ", received: " + actual);
	}
public static void main(String[] args) 	{
	int[] simple = {1, 2, 3, 4, 5, 6};
	int[] simple2 = {1, 2, 3, 4, 5, 6, 7};

	int[] reversed = {6, 5, 4, 3, 2, 1};
	int[] reversed2 = {6, 5, 4, 3, 2};

	int [] empty = {};
	test(reversed, reverse(simple));
	test(simple, reverse(reversed));
	test(true, isIncreasing(simple));
	test(false, isIncreasing(reversed));

	// you could also do
	test("[6, 5, 4, 3, 2, 1]", reverse(simple));
	test("[1, 2, 3, 4, 5, 6]", reverse(reversed));
	test("true", isIncreasing(simple));
	test("false", isIncreasing(reversed));
/////////////////////////////////////////////	
	test ("3.5", average(simple));
	test ("4.0", average(simple2));

	try {
	    test("null", average(null));
	    System.out.println("test failed - exception not thrown");
	} catch(IllegalArgumentException e) {
	    System.out.println("caught the expected illegal argument exception");
	}
	test("0.0" , average(empty));
//////////////////////////////////////////////	
	test ("[1, 3, 5]", evenIndicesOnly(simple));
	test ("[]", evenIndicesOnly(empty));
	test("null",evenIndicesOnly(null));
//////////////////////////////////////////////	
	test(true, isIncreasing(simple));
	test(false, isIncreasing(reversed));
	test(true, isIncreasing(null));
	test(true, isIncreasing(empty));
//////////////////////////////////////////////
	test("[6, 5, 4, 3, 2, 1]", reverse(simple));
	test("[1, 2, 3, 4, 5, 6]", reverse(reversed));
	test("[7, 6, 5, 4, 3, 2, 1]", reverse(simple2));
	test("[2, 3, 4, 5, 6]", reverse(reversed2));
	test("null", reverse(null));
	test("[]", reverse(empty));
	
//////////////////////////////////////////////
	try {
	    test("null",concatenate(null, null));
	    System.out.println("test failed - exception not thrown");
	} catch(IllegalArgumentException e) {
	    System.out.println("caught the expected illegal argument exception");
	}
	
    test("[1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2] ",concatenate(simple2, reversed2));
    test("[1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2,1] ",concatenate(simple, reversed));
    test("[1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2] ",concatenate(simple, reversed2));

    test("[] ",concatenate(empty, empty));
//////////////////////////////////////////////
    try {
	    test("null",endToEnd(null, null));
	    System.out.println("test failed - exception not thrown");
	} catch(IllegalArgumentException e) {
	    System.out.println("caught the expected illegal argument exception");
	}
    test("[1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6]",endToEnd(simple, reversed));
    test("[1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6]", endToEnd(simple2, reversed));
    test("[1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6]", endToEnd(simple, reversed2));
    test ("[]", endToEnd(empty, empty));
//////////////////////////////////////////////
   
    reverseInPlace(simple);
    test("[6, 5, 4, 3, 2, 1]", simple);	
    reverseInPlace(simple2);
    test("[7, 6, 5, 4, 3, 2, 1]", simple2);
    reverseInPlace(reversed);
    test("{1, 2, 3, 4, 5, 6}", reversed);
    reverseInPlace(reversed2);
    test("[2, 3, 4, 5, 6]", reversed2);
    test("null", null);
    test("[]", empty);

	
	
	
	
	
	
	
	

	

	
	
	
	
}
	
	
}
