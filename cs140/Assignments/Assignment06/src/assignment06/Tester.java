package assignment06;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import assignment06.TriangleClassifier.Triple;
import static assignment06.TriangleClassifier.createTriple;
import static assignment06.TriangleClassifier.removeScalene;
public class Tester {
	public static void main (String args[]){

		
		ArrayList<Triple> triangles = new ArrayList <Triple>(Arrays.asList(createTriple(3,4,5), createTriple(3,3,3), createTriple(5,5,2), createTriple(2,3,5), createTriple(2,2,3),createTriple(4,5,6)));
		for(int i=0; i < triangles.size(); i++ ){
			System.out.println(triangles.get(i).toString());
		}

		System.out.print("-------------------Sorted------------------\n");
		
		Collections.sort(triangles);
		for(int i=0; i < triangles.size(); i++ ){
			System.out.println(triangles.get(i).toString());
		}
		System.out.print("-------------------Scalene Removed------------------\n");

		TriangleClassifier.removeScalene(triangles);
		for(int i=0; i < triangles.size(); i++ ){
			System.out.println(triangles.get(i).toString());
		}

	}

}
