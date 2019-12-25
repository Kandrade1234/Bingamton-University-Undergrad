package assignment05;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Lodging implements TravelExpenses{

	private LocalDate startDate;
	private LocalDate endDate;
	private String lodgingName;
	private int numberOfNights;
	private double costOfStay;
	
	
	public Lodging(LocalDate start, LocalDate end, String name,  double cost){
		startDate = start;
		endDate = end;
		lodgingName = name;
		costOfStay = cost;
		numberOfNights =(int)ChronoUnit.DAYS.between(startDate, endDate);
	
	}
	@Override
	public double amountToReimburse()
	{
		return costOfStay;
	}
	
	@Override
	public String getDescription()
	{
		//		return mealType + " on " + date;

		return startDate + " to " + endDate +" "+ lodgingName + " " + numberOfNights + " day(s) stayed ";
	}
	public LocalDate getStartDate() {
		return startDate;
	}
	public LocalDate getEndDate() {
		return endDate;
	}
	public int sequenceNo(){
	return 6;
	}
}
