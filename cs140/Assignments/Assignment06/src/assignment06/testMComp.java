package assignment06;

import static org.junit.Assert.*;

import org.junit.Test;

public class testMComp {

	@Test
	public void testMin() {
		assertEquals(1.59 , MCompTester.cheapest(MCompTester.makeTest()).getPrice(), 1e-6);
		assertEquals("Apple Pie" , MCompTester.cheapest(MCompTester.makeTest()).getName());
	}
	
	@Test
	public void testMax(){
		assertEquals(4.29, MCompTester.dearest(MCompTester.makeTest()).getPrice(), 1e-6);
		assertEquals("Burrito" , MCompTester.dearest(MCompTester.makeTest()).getName());
	}
	@Test
	public void testLongest(){
		assertEquals( "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",MCompTester.longestDescr(MCompTester.makeTest()).getDescription());
		assertEquals("Veggie Burger and Air Fries" , MCompTester.longestDescr(MCompTester.makeTest()).getName());

	}

}
