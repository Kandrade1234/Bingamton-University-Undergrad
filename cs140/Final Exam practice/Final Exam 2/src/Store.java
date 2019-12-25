import java.util.ArrayList;
public class Store {
	private Counter counts;
	private Filter flt;


	public Store(ArrayList<Integer> list, Filter in){
		flt = in;
		int max = -1;
		for(int i =0; i < list.size(); i++){
			if(list.get(i)> max)
				max = list.get(i);
		}
		counts = new Counter(max +1);
		for(Integer j : list){
			if(flt.filter(j)){
				counts.inc(j);
			}
		}
	}
	public void add(int j){
		if(flt.filter(j))
			counts.inc(j);
		
	}
	public int get(int k){
		return counts.getCount(k);
	}



}
