package assignment07;
import java.io.PrintWriter;
import java.util.Random;
public class P19_1 {

	public static void main(String args[]){
		//UP TO 10^8
		for(int i=1; i<9; i++){
			int k =1;
			for(int j =0; j < i; j++){
				k *= 10;
			}
			Random generator = new Random();
			long t1 = System.currentTimeMillis();
			//do the process
			//FILTER NEEDS A BOOLEAN LAMBDA EXPRESSION
			long count = generator.longs(0,k).parallel().filter(z->z%2==1).limit(k).count();
			long t2 = System.currentTimeMillis();
			System.out.println(count + ": " + (t2-t1));	
		}		
	}
	
	
	
	
}
