package assignment04;

public class Demo {
	public static void main(String[] args)
	{
		
		FlexibleChoiceQuestion test = new FlexibleChoiceQuestion("Which are multiples of 2?");
//Testing input from keyboard
		test.addChoice("3");
		test.addChoice("4");
		test.addChoice("6");
		test.addChoice("7");
		test.addChoice("8");
		test.addAnswer(2);
		test.addAnswer(3);
		test.addAnswer(5);
	//	test.checkAnswer("2 3 5");
		test.presentQuestion();
		
//Testing hardcoded  incorrect answers (all incorrect)
		System.out.println("\n");
		FlexibleChoiceQuestion test2 = new FlexibleChoiceQuestion("Which are multiples of 2?");
		test2.addChoice("3");
		test2.addChoice("4");
		test2.addChoice("6");
		test2.addChoice("7");
		test2.addChoice("8");
		test2.addAnswer(2);
		test2.addAnswer(3);
		test2.addAnswer(5);
		test2.display();
		test2.checkAnswer("1 4 6");
//Testing hardcoded repeated answers (repeated haardcoded answers)
		
		System.out.println("\n");
		FlexibleChoiceQuestion test3 = new FlexibleChoiceQuestion("Which are multiples of 2?");
		test3.addChoice("3");
		test3.addChoice("4");
		test3.addChoice("6");
		test3.addChoice("7");
		test3.addChoice("8");
		try{		
			test3.addAnswer(0);
		}catch (IllegalArgumentException e)
		{
			System.out.println(e);
		}
		test3.addAnswer(2);
		test3.addAnswer(3);
		test3.addAnswer(5);
		test3.display();
		test3.checkAnswer("2 2 3");

//Testing hardcoded some correct some incorrect answers && illegalargumentexception
		
		System.out.println("\n");
		FlexibleChoiceQuestion test4 = new FlexibleChoiceQuestion("Which are multiples of 2?");
		test4.addChoice("3");
		test4.addChoice("4");
		test4.addChoice("6");
		test4.addChoice("7");
		test4.addChoice("8");
		try{
		test.addChoice("2", true);
		}catch (UnsupportedOperationException e)
		{
			System.out.println(e);
		}
			
		test4.addAnswer(2);
		test4.addAnswer(3);
		test4.addAnswer(5);
		test4.display();
		test4.checkAnswer("2 6 3");

//Testing provided choice question		
		System.out.println("\n");
		ChoiceQuestion choiceTest = new ChoiceQuestion("What course is this?");
		choiceTest.addChoice("Cs120", false);
		choiceTest.addChoice("Cs140", true);
		choiceTest.display();
		System.out.println(choiceTest.checkAnswer("2"));
//Testing question
		
		System.out.println("\n");
		Question quesTest = new Question("What course is this?", "cs 140");
		quesTest.display();
		System.out.println(quesTest.checkAnswer("cs 140"));
		
		
	}
}
