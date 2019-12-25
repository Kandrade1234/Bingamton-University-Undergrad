package exam02;

import java.util.ArrayList;

public class Map {

	
	
	
	public static ArrayList<Double> map(ArrayList<Double> list, DoubleFunction func){
		ArrayList<Double> update = new ArrayList<>();		
		for(int i = 0; i < list.size(); i++)
			update.add(func.apply(list.get(i)));
	
		return update;

	}
	
	
}
