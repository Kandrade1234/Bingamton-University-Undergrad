package assignment05;

import java.time.LocalDate;

public class Meal implements TravelExpenses {
	private MealType mealType;
	private double amountPaid;
	private LocalDate mealDate;
	
	
	@Override
	public LocalDate getStartDate() {
		return mealDate;
	}
	public LocalDate getEndDate() {
		return mealDate;
	}
	public Meal(MealType meal, double amount, LocalDate dat)
	{
		mealType = meal;
		amount = amountPaid;
		mealDate = dat;
	}
	
	@Override
	public double amountToReimburse(){
		return Math.max(amountPaid, mealType.getMax());
	}
	
	@Override
	public String getDescription()
	{
		return mealType + " on " + mealDate;
	}
	public MealType getMealType(){
		return mealType;
	}
}
