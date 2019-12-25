import java.util.ArrayList;

public class Select {

	private ArrayList<Integer> input;
	private Filter Tester;
	
	public Select(ArrayList<Integer> input, Filter Tester){
		this.input = input;
		this.Tester = Tester;
	}
	
	public boolean apply(int n){
		return Tester.test(n);
	}
	
	 public ArrayList<Integer> getSelected(){
		
		 ArrayList<Integer> second = new ArrayList<Integer>();
		 for(int i =0; i < input.size(); i++)
		 {
			 if(apply(input.get(i))){
				 second.add(input.get(i));
			 }
		 }
		 return second; 
	 }
	 
	 
	
	
}
