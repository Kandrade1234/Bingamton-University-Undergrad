import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Arrays;
import org.junit.Before;
import org.junit.Test;
public class SubStoreTest {
	ArrayList<Integer> list = new ArrayList<Integer>(Arrays.asList(
			2, 5, 6, 8, 13, 8, 4, 9, 2, 12, 0, 2, 5, 7));
	SubStore test;
	@Before
	public void setUp() throws Exception {
		test = new SubStore(list, i -> i >= 0 && i <= 9);
		test.add(5);
		test.add(0);
		test.add(7);
	}
	@Test
	public void testGet() {
		assertEquals(2, test.get(0));
		assertEquals(2, test.get(8));
		assertEquals(0, test.get(12));
	}
	@Test
	public void testGetEvens() {
		
		assertEquals(7 , test.getEvens());
		
	}
}