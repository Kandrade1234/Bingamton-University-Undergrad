package assignment02;
import java.util.Arrays;
import java.util.Optional;
public class Tester {
	public static void main (String [] args)
	{		
		System.out.println("\n----------NOW-TESTING-UTULITIES02---------------------------------------------------------------");
						//TEST 0
		System.out.println("Expected value 0");
		System.out.println(Utilities02.countNulls(null));
		Object[] test = {}; 
		System.out.println("Expected value 0");
		System.out.println(Utilities02.countNulls(test));
		System.out.println("Expected value 0");
		String[] string = {"Hello", "My", "Name", "is", "Bob"};
		System.out.println(Utilities02.countNulls(string));
		String[] string2 = {"Hello", null, "Name", null, "Bob"};
		System.out.println("Expected value 2");
		System.out.println(Utilities02.countNulls(string2));

		
						//TEST 1
		System.out.println("\nNOW TESTING COUNTSPACES ");
		System.out.println("Expected value is -1");	
		System.out.println(Utilities02.countSpaces(null));	
		
		System.out.println("Expected value is 0");	
		System.out.println(Utilities02.countSpaces(""));
		
		System.out.println("Expected value is 0");	
		System.out.println(Utilities02.countSpaces("Kevin"));
		
		System.out.println("Expected value is 3");	
		System.out.println(Utilities02.countSpaces("My name is Kevin"));
						//TEST 2
		System.out.println("\nNOW TESTING COUNTSPACES2");
		System.out.println("Expected value is -1");	
		System.out.println(Utilities02.countSpaces2(null));	
		
		System.out.println("Expected value is 0");	
		System.out.println(Utilities02.countSpaces2(""));
		
		System.out.println("Expected value is 0");	
		System.out.println(Utilities02.countSpaces2("Kevin"));
		
		System.out.println("Expected value is 3");	
		System.out.println(Utilities02.countSpaces2("My name is Kevin"));
						//TEST 3
		System.out.println("\nNOW TESTING FIRST ");
		System.out.println("Expected output is null ");
		System.out.println(Utilities02.first(null));	

		System.out.println("Expected output is the empty string");
		System.out.println(Utilities02.first(""));
	
		System.out.println("Expected output is an empty space");
		System.out.println(Utilities02.first("   "));
	
		System.out.println("Expected output is Bob ");
		System.out.println(Utilities02.first(" Bob "));
		
		System.out.println("Expected output is Joe");
		System.out.println(Utilities02.first("Joe"));
		
		System.out.println("Expected output is Nathaly");
		System.out.println(Utilities02.first( "Nathaly likes cake "));
	
		System.out.println("Expected output is Kevin");
		System.out.println(Utilities02.first("Kevin likes cake"));
						//TEST 4
		System.out.println("\nNOW TESTING REST");
		System.out.println("Expected output is null ");
		System.out.println(Utilities02.rest(null));	

		System.out.println("Expected output is the empty string");
		System.out.println(Utilities02.rest(""));
	
		System.out.println("Expected output is an empty space");
		System.out.println(Utilities02.rest("   "));
	
		System.out.println("Expected output is the empty string ");
		System.out.println(Utilities02.rest(" Bob "));
		
		System.out.println("Expected output is the empty string");
		System.out.println(Utilities02.rest("Joe"));
		
		System.out.println("Expected output is likes cake");
		System.out.println(Utilities02.rest( "Nathaly likes cake "));
	
		System.out.println("Expected output is likes cake");
		System.out.println(Utilities02.rest("Kevin likes cake"));
						//TEST 5
		System.out.println("\nNOW TESTING WITHOUTEXTRASPACES");
		System.out.println("Expected output is Nathaly likes cake");
		System.out.println(Utilities02.withoutExtraSpaces( "Nathaly  likes   cake "));
	
		System.out.println("Expected output is Kevin likes cake");
		System.out.println(Utilities02.withoutExtraSpaces("   Kevin       likes   cake"));
		
		System.out.println("Expected output is Joe");
		System.out.println(Utilities02.withoutExtraSpaces("     Joe    "));
						//TEST 6
		System.out.println("\nNOW TESTING splitOnSpaces");
		System.out.println("Expected output is null");
		System.out.println(Arrays.toString(Utilities02.splitOnSpaces(null)));
	
		System.out.println("Expected output is the empty string");
		System.out.println(Arrays.toString(Utilities02.splitOnSpaces("")));
		
		System.out.println("Expected output is 'This, is, a, test, to, see, how, this, program, will, handle, this'");
		System.out.println(Arrays.toString(Utilities02.splitOnSpaces("This is a test to see how this program will handle this")));
						//TEST 7
		System.out.println("\nNOW TESTING splitOnSpaces1");
		System.out.println("Expected output 'should, give, an, array, of, these, words, separated, by, commas'");
	    Optional<String[]> array = Utilities02.splitOnSpaces1(" should give an array of   these words  separated by commas   ");
		if(array.isPresent()) {
			System.out.println(Arrays.toString(array.get()));
		} else {
			System.out.println("The input was null or empty");
		}
		
		System.out.println("Expected output null");
		Optional<String[]> array2 = Utilities02.splitOnSpaces1(null);
		if(array2.isPresent()) {
			System.out.println(Arrays.toString(array2.get()));
		} else {
			System.out.println("-The input was null");
		}
		
		System.out.println("Expected output is the empty string");
		Optional<String[]> array3 = Utilities02.splitOnSpaces1("");
		if(array3.isPresent()) {
			System.out.println(Arrays.toString(array3.get()));
		} else {
			System.out.println("-The input was empty");
		}
						//TEST 8
		System.out.println("\nNOW TESTING STRINGLENGTHS");
		System.out.println("Expected output 5, 5, 4 ");
		System.out.println(Arrays.toString(Utilities02.strLengths("Kevin likes cake")));

		System.out.println("Expected output is the empty array");
		System.out.println(Arrays.toString(Utilities02.strLengths("")));
		
		System.out.println("Expected output is null");
		System.out.println(Arrays.toString(Utilities02.strLengths(null)));
//////////////////////INSTANCE METHOD CLASS///////////////////////////////////////////////////////////////////////////////////////
						//TEST 1
		System.out.println("\n----------NOW-TESTING-INTANCEMETHODVERSION---------------------------------------------------------------");
		System.out.println("\nNOW TESTING COUNTSPACES ");
		System.out.println("Expected value is -1");	
		InstanceMethodVersion one = new InstanceMethodVersion(null);
		System.out.println(one.countSpaces());
		
		System.out.println("Expected value is 0");	
		InstanceMethodVersion two = new InstanceMethodVersion("");
		System.out.println(two.countSpaces());

		System.out.println("Expected value is 0");	
		InstanceMethodVersion three = new InstanceMethodVersion("Kevin");
		System.out.println(three.countSpaces());

		System.out.println("Expected value is 3");	
		InstanceMethodVersion four = new InstanceMethodVersion("My name is Kevin");
		System.out.println(four.countSpaces());

		
						//TEST 2
		System.out.println("\nNOW TESTING COUNTSPACES2 ");
		System.out.println("Expected value is -1");	
		InstanceMethodVersion five = new InstanceMethodVersion(null);
		System.out.println(five.countSpaces2());
	
		System.out.println("Expected value is 0");	
		InstanceMethodVersion six = new InstanceMethodVersion("");
		System.out.println(six.countSpaces2());
		
		System.out.println("Expected value is 0");	
		InstanceMethodVersion seven = new InstanceMethodVersion("Kevin");
		System.out.println(seven.countSpaces2());
		
		System.out.println("Expected value is 3");	
		InstanceMethodVersion eigth = new InstanceMethodVersion("My name is Kevin");
		System.out.println(eigth.countSpaces2());
		
						//TEST 3

		System.out.println("\nNOW TESTING WITHOUTEXTRASPACES");
		System.out.println("Expected output is Nathaly likes cake");
		InstanceMethodVersion nine = new InstanceMethodVersion("Nathaly  likes   cake ");
		System.out.println(nine.withoutExtraSpaces());
		
		System.out.println("Expected output is Kevin likes cake");
		InstanceMethodVersion ten = new InstanceMethodVersion("   Kevin       likes   cake");
		System.out.println(ten.withoutExtraSpaces());
		
		System.out.println("Expected output is Joe");
		InstanceMethodVersion eleven = new InstanceMethodVersion("     Joe    ");
		System.out.println(eleven.withoutExtraSpaces());
						//TEST 4
		
		System.out.println("\nNOW TESTING FIRST ");
		System.out.println("Expected output is null");
		InstanceMethodVersion twelve = new InstanceMethodVersion(null);
		System.out.println(twelve.first());
		
		System.out.println("Expected output is the empty string");
		InstanceMethodVersion thirteen = new InstanceMethodVersion("");
		System.out.println(thirteen.first());
		
		System.out.println("Expected output is an empty space");
		InstanceMethodVersion fourteen = new InstanceMethodVersion("   ");
		System.out.println(fourteen.first());
		
		System.out.println("Expected output is Bob");
		InstanceMethodVersion fifteen = new InstanceMethodVersion(" Bob ");
		System.out.println(fifteen.first());
		
		System.out.println("Expected output is Joe");
		InstanceMethodVersion sixteen = new InstanceMethodVersion("Joe");
		System.out.println(sixteen.first());
	
		System.out.println("Expected output is Nathaly");
		InstanceMethodVersion seventeen = new InstanceMethodVersion("Nathaly likes cake ");
		System.out.println(seventeen.first());
	
		System.out.println("Expected output is Kevin");
		InstanceMethodVersion eighteen = new InstanceMethodVersion("Kevin likes cake");
		System.out.println(eighteen.first());
						//TEST 5

		System.out.println("\nNOW TESTING REST");
		System.out.println("Expected output is null");
		InstanceMethodVersion nineteen = new InstanceMethodVersion(null);
		System.out.println(nineteen.rest());
		
		System.out.println("Expected output is the empty string");
		InstanceMethodVersion twenty = new InstanceMethodVersion("");
		System.out.println(twenty.rest());
		
		System.out.println("Expected output is an empty space");
		InstanceMethodVersion a = new InstanceMethodVersion("   ");
		System.out.println(a.rest());
		
		System.out.println("Expected output is the empty string");
		InstanceMethodVersion b = new InstanceMethodVersion(" Bob ");
		System.out.println(b.rest());
		
		System.out.println("Expected output is the empty string");
		InstanceMethodVersion c = new InstanceMethodVersion("Joe");
		System.out.println(c.rest());
		
		System.out.println("Expected output is likes cake");
		InstanceMethodVersion d = new InstanceMethodVersion("Nathaly likes cake ");
		System.out.println(d.rest());
		
		System.out.println("Expected output is likes cake");
		InstanceMethodVersion e = new InstanceMethodVersion("Kevin likes cake");
		System.out.println(e.rest());
					//TEST 6
		
		System.out.println("\nNOW TESTING splitOnSpaces");
		System.out.println("Expected output is null");
		InstanceMethodVersion f = new InstanceMethodVersion(null);
		System.out.println(Arrays.toString(f.splitOnSpaces()));
		
		System.out.println("Expected output is the empty string");
		InstanceMethodVersion g = new InstanceMethodVersion("");
		System.out.println(Arrays.toString(g.splitOnSpaces()));
		
		System.out.println("Expected output is 'This, is, a, test, to, see, how, this, program, will, handle, this'");
		InstanceMethodVersion h = new InstanceMethodVersion("This is a test to see how this program will handle this");
		System.out.println(Arrays.toString(h.splitOnSpaces()));
		
					//TEST 7
	
		System.out.println("\nNOW TESTING strLengths");
		System.out.println("Expected output 5, 5, 4");
		InstanceMethodVersion i = new InstanceMethodVersion("Kevin likes cake");
		System.out.println(Arrays.toString(i.strLengths()));
		
		System.out.println("Expected output is the empty array");
		InstanceMethodVersion j = new InstanceMethodVersion("");
		System.out.println(Arrays.toString(j.strLengths()));
		
		System.out.println("Expected output is null");
		InstanceMethodVersion k = new InstanceMethodVersion(null);
		System.out.println(Arrays.toString(k.strLengths()));
	}
}
