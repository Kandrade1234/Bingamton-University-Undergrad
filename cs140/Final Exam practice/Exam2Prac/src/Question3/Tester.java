package Question3;

import java.util.ArrayList;

public class Tester {

	public static void main(String[] args){
		Ques one = new Ques (12, '+', 17);
		Ques two = new Ques (12, '/', 5);

		Choice onev2 = new Choice(5, '*', 7);
		onev2.add(12);
		onev2.add(31);
		onev2.add(35);
		onev2.add(57);
		ArrayList<Ques> store = new ArrayList<Ques>();


		store.add(one);
		store.add(onev2);
		store.add(two);

		for (int i = 0; i < store.size(); i++){
			store.get(i).presentQuestion();
		}


	}
}
