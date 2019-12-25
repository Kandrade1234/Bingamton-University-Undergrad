package exam02;

import java.util.ArrayList;

public class Recursion {

	
	public static int maxElement(ArrayList<Integer> list){
	
		int max = 0;
		if(list.size() == 1){
			max = list.get(0);
			return max;
		}
		else {
			for(int i=0; i < list.size(); i++){
				Math.max(max, i);
				list.remove(i);
				return Recursion.maxElement(list);
			}
		}
		return max;
	}
	
	public static int gcd(int a, int b){
		
		if(b == 0)
			return a;
		else 
			return gcd(b, a %b);
		
		
	}
	
	
	
}
