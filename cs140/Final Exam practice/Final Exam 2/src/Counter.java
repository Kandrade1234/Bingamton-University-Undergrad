
public class Counter {

	
	
	private int [] counts;
	public Counter (int length){
		counts = new int[length];
	}
	
	
	public void inc(int i) {
		counts[i]++;
	}
	public int getCount(int i){
		return counts[i];
	}
	
}
