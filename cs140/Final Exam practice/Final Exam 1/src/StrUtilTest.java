import static org.junit.Assert.*;
import java.util.ArrayList;
import org.junit.Test;




public class StrUtilTest {
	@Test
	public void testCount() {
		//MAKE AN ARRAYLIST list WITH 3 ELEMENTS THAT TOGETHER CONTAIN AT LEAST 5 DIFFERENT
		//WORDS (PLEASE NO MORE THAN 8) THAT START AND END WITH A VOWEL AND AT
		//LEAST 5 WORDS THAT DO NOT HAVE THE PROPERTY.
		//PUT THE VALUE IN THE assertEquals TO MAKE THE TEST SUCCEED.
		//SOME OTHER WORDS THAT HAVE THE PROPERTY ARE eagle, eye, Europe, age, acne, apple,
		//agile, endive, endure, imitate, image, innovate, olive, aubergine, automate, undulate
		

		ArrayList<String> list = new ArrayList<String>();
		list.add("ello hi oa my name is kevin angle acute ACUTE");
		list.add("ACUTE");
		list.add("apple is my fruit");

		Util ob = new Util(new ArrayList<String>(list));

		//ob.Count();
		
		Util obj = new Util(list);
		
		
		assertEquals(7, obj.Count());
	}
}