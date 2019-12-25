import java.util.ArrayList;

public class ExtraSelect extends Select {

	private ArrayList<Filter> list = new ArrayList<Filter>();

	public ExtraSelect(ArrayList<Integer> input, Filter Tester){
		super(input, Tester);
	}

	public void add(Filter f){
		list.add(f);
	}

	@Override
	public boolean apply(int n){
		boolean tester = true;

		for(int i = 0; i < list.size(); i++){

			if(!super.apply(n)) {
				return false;
			}
			if(!list.get(i).test(n)){
				System.out.println("errased: " + n);
				return false;
			}

		}



		return tester;


	}
}