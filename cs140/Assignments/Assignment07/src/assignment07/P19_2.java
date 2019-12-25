package assignment07;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.stream.Stream;


public class P19_2 {

	public static void main(String args[]){
		try (PrintWriter output = new PrintWriter("test3.txt")) {
		Stream.iterate(BigInteger.ONE,i -> i.add(BigInteger.ONE)).map(i-> i.multiply(i)).filter(P19_2::palindrome).limit(90).forEach(output::println);

		}catch(FileNotFoundException e)
		{
			
		}
	}
	static boolean palindrome(BigInteger n){
		
		StringBuilder pal = new StringBuilder("" + n);
		return (""+n).equals(pal.reverse().toString());
		
		
	}
	
}