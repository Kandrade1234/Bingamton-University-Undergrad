import static org.junit.Assert.*;
import java.util.ArrayList;
import org.junit.Test;
public class Ques2Test {
	@Test
	public void testOfLength1() {
		Ques2 test = new Ques2(null);
				assertNull(test.ofLength(1)); //SUCCEEDS IF test.ofLength(1) IS null
	}
	@Test
	public void testOfLength2() {
		//MAKE AN ARRAYLIST lst OF STRING AND ADD 4 STRINGS OF DIFFERENT LENGTHS
		//SO THAT THIS TEST SUCCEEDS
		ArrayList<String> lst = new ArrayList<String>();
		lst.add("whatt");
		lst.add("hello");
		lst.add("hahahahaha");
		lst.add("this is my fourth");
		
		Ques2 test = new Ques2(lst);
		assertEquals(0, test.ofLength(2).size());
	}
	@Test
	public void testOfLength3() {
		//MAKE AN ARRAYLIST lst OF STRING AND ADD 4 STRINGS
		//AND MAKE AN ARRAYLIST exp AND ADD 2 STRINGS OF LENGTH 3
		//SO THAT THIS TEST SUCCEEDS
		
		ArrayList<String> lst = new ArrayList<String>();
		lst.add("wha");
		lst.add("hel");
		lst.add("haha");
		lst.add("this is my fourth");
		 ArrayList<String> exp = new ArrayList<String>();
		 exp.add("wha");
		 exp.add("hel");
		
		Ques2 test = new Ques2(lst);
		assertEquals(exp, test.ofLength(3));
		//Note that the assertEquals will use the equals method of ArrayList.
		//That method checks the two lists have the same size and then applies the
		//equals method to each corresponding pair: list1.get(i).equals(list2.get(i))
		//for each i.
		// That means that exp and test.ofLength(3) have 2 elements with equal
		// first Strings and equal second Strings.
	}
}