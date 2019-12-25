package assignment05;

import java.time.LocalDate;

public class TravelByOwnCar implements TravelExpenses {

	private double milesDriven;
	LocalDate startDate;
	LocalDate endDate;
	
	public TravelByOwnCar(LocalDate start, LocalDate end){
		startDate = start;
		endDate = end;
	//	milesDriven = 0;
	}
	
	public void addMiles (double miles)
	{
		milesDriven += miles;
	}
	
	@Override
	public String getDescription (){
		return "Own car used, miles driven: " +  milesDriven;
		}
	
	@Override
	public double amountToReimburse(){
		return milesDriven * mileage;
	}
	
	public LocalDate getStartDate() {
		return startDate;
	}
	public LocalDate getEndDate() {
		return endDate;
	}
	public int sequenceNo(){
		return 5;
	}
}
