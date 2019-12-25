package exam02;

import java.util.ArrayList;

public class Reduce {
	public static int reduce(ArrayList<Integer> list, int baseVal, BinaryFunction func){
		int retVal = baseVal;
		
		for(int i = 0; i < list.size(); i++){
			retVal = func.apply(retVal, list.get(i));
		}
		
		return retVal;
	}
}
