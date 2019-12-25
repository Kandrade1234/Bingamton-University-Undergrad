package assignment05;

import java.util.Comparator;

public class ExpensesOrder implements Comparator <TravelExpenses>{
	public int compare(TravelExpenses arg0, TravelExpenses arg1){
		if((arg0 instanceof Meal) &&(arg1 instanceof Meal) ) return ((Meal)arg0).getMealType().compareTo(((Meal)arg1).getMealType());


		return arg0.sequenceNo() - arg1.sequenceNo();
	}
}
