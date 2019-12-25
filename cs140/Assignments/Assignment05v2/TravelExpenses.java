package assignment05;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public interface TravelExpenses {
	double mileage = 0.53;
	double BREAKFAST_MAX = 8.0;
	double LUNCH_MAX = 10.0;
	double DINNER_MAX = 40.0;


	public double amountToReimburse();
	default String getDescription(){
		throw new UnsupportedOperationException ("Must be implemented by class");
	}

	public static void printReport(ArrayList<TravelExpenses> list)
	{
		//if(TravelExpenses::getStartDate != TravelExpenses::getEndDate)
			//System
		Collections.sort(list, Comparator.comparing(TravelExpenses::getStartDate).thenComparing(new ExpensesOrder()));
		for (int i =0; i < list.size(); i++){
			String s = String.format("$%.2f", list.get(i).amountToReimburse()); 
			System.out.println(list.get(i).getDescription() + s);
		}
		int sum =0;
		for (int i =0; i < list.size(); i++){
			sum+=list.get(i).amountToReimburse();
		}
		System.out.println("Total Expenses: " + sum);

	}

	default LocalDate getStartDate() {
		return LocalDate.now();
	}
	default LocalDate getEndDate() {
		return LocalDate.now();
	}
	default int sequenceNo() {
		return Integer.MAX_VALUE;
	}

}
