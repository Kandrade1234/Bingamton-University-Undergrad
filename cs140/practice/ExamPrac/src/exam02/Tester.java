package exam02;

import java.util.Arrays;
import java.util.ArrayList;

import org.junit.Test;

import static org.junit.Assert.*;

public class Tester {
	public static final double DELTA = 1e-6;
	
    @Test
    public void testGCD() {
        assertEquals(7, Recursion.gcd(14, 7));
        assertEquals(7, Recursion.gcd(7, 14));
        assertEquals(7, Recursion.gcd(21, 14));
    }

    @Test
    public void testMax() {
        assertEquals(6,
                     Recursion.maxElement(new ArrayList<>(Arrays.asList(1, 2, 3,
                                                                        4, 5, 6))));
    }
    
    @Test
    public void testFunctions() {
        Identity id = new Identity();
        assertEquals(10, id.apply(10), DELTA);
        Power f1 = new Power(3);
        assertEquals(27, f1.apply(3), DELTA);
        Abs f2 = new Abs();
        assertEquals(3, f2.apply(-3), DELTA);
    }

     @Test
    public void testMap() {
        ArrayList<Double> exp = new ArrayList<>();
        ArrayList<Double> list = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            list.add(i + 0.0);
            exp.add(Math.pow(i, 2));
        }
        assertEquals(exp, Map.map(list, new Power(2)));
    }
    
    
   @Test
	public void testQ3() {
    	double[] array = {1.2, 3, 0.75, 0.5, 4, 2.7};
  	MinMax mm = new MinMax(array);
   	assertEquals(0.5, mm.measure(), DELTA);
    	assertEquals(4.0, mm.value(), DELTA);
    	Range r = new Range(array);
    	assertEquals(3.5, r.measure(), DELTA);
    	assertEquals(8.0, r.value(), DELTA);

	} 
}
