package assignment05;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class TravelByRentalCar implements TravelExpenses {
	private double totalRentalCost;
	private double fuelCost;
	private double fuelUsed;
	private int numberOfDaysRented;
	private String rentalCompany;	
	private LocalDate startDate;
	private LocalDate endDate;

	public TravelByRentalCar(double TRC, String RC, LocalDate SD, LocalDate ED)
	{
		totalRentalCost = TRC;
		rentalCompany = RC;
		startDate = SD;
		endDate = ED;

		numberOfDaysRented = (int)ChronoUnit.DAYS.between(startDate, endDate);
	}
	public void addFuel(double numGallons, double cost)
	{
		fuelUsed += numGallons;
		fuelCost += cost;
	}

	@Override
	public String getDescription() 
	{
		return "Took a rental car from " + rentalCompany + " for " + numberOfDaysRented + " day rented, from " + startDate + " to " + endDate + " , " + Math.round(fuelUsed) + " gallons of fuel used."; 
	}
	
	public double amountToReimburse()
	{
		return totalRentalCost + fuelCost;
	}
	public LocalDate getStartDate() {
		return startDate;
	}
	public LocalDate getEndDate() {
		return endDate;
	}
	public int sequenceNo(){
		return 4;
	}
	

}
