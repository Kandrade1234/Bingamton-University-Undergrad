package lab08;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;

import org.junit.Test;

public class test {

	@Test
	public void test1() {
		assertEquals(1, Recursion.factorial(1));
		assertEquals(1, Recursion.factorial(0));
		assertEquals(24, Recursion.factorial(4));
	}
	
	@Test
	public void test2(){
		assertEquals(1, Recursion.squareRoot(1),1e-6);
		assertEquals(0, Recursion.squareRoot(0),1e-6);
		assertEquals(2, Recursion.squareRoot(4),1e-6);
	}

	@Test
	public void test3(){
		assertEquals(6, Recursion.sum(new ArrayList<Integer>(Arrays.asList(1,2,3))),1e-6);	
	}
	
	@Test
	public void test4(){
		assertEquals(6, Recursion.sum(new int [] {1,2,3}),1e-6);

	}
	
	@Test
	public void test5(){
		assertEquals(45, Recursion.binomialCoefficient(10,8),1e-6);
		assertEquals(125970, Recursion.binomialCoefficient(20,8),1e-6);

	}
}
