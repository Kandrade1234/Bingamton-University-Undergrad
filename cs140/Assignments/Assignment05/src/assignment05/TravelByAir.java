package assignment05;
import java.time.LocalDate;
public class TravelByAir implements TravelExpenses {

	private LocalDate outboundStartDate;
	private LocalDate inboundEndDate;
	private String airlines; 
	private double totalCost;
	
	
	
	
	public TravelByAir(LocalDate out, LocalDate in, String lines, double totalCost){
		outboundStartDate = out;
		inboundEndDate = in;
		airlines = lines;
		this.totalCost = totalCost;	
	}
	@Override
	public double amountToReimburse(){
		return totalCost;
	}
	
	@Override
	public String getDescription()
	{
		return "Took the plane from the " + airlines + " company from " + outboundStartDate + " to " + inboundEndDate + " ";
	}
	
	public LocalDate getoutboundStartDate() {
		return outboundStartDate;
	}
	public LocalDate getinboundEndDate() {
		return inboundEndDate;
	}
	public int sequenceNo(){
		return 1;
	}
	
}
