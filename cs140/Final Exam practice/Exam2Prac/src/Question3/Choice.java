package Question3;


public class Choice extends Ques{
	private int [] array = new int [4];
	private int indexAvail = 0;
	private int correct = 5; // 5 means none of the above, always 4 choices
	
	public Choice(int x, char op, int y){
		super(x,op,y);
		
		
	}
	
	public boolean checkAnswer(int ans){
		if(correct == ans) return true;
		else return false;
	}
	
	public void add(int x){
		array[indexAvail] = x;
		indexAvail++;
		if(super.checkAnswer(x))  correct = indexAvail - 1;
	}
	public void display(){
		super.display();
		for(int i =0; i < array.length; i++)
			System.out.println(i + " :" + array[i] );
		System.out.println(5 + " :" + "None of the above");
		System.out.println("Which line number has the correct answer?");
		
		
	}
	
}