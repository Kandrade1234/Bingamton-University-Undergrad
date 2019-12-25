package assignment05;
import java.time.LocalDate;
public class TravelByBus implements TravelExpenses {

	private LocalDate outboundStartDate;
	private LocalDate inboundEndDate;
	private String busLine; 
	private double totalCost;
	
	
	
	
	public TravelByBus(LocalDate out, LocalDate in, String lines, double totalCost){
		outboundStartDate = out;
		inboundEndDate = in;
		busLine = lines;
		this.totalCost = totalCost;	
	}
	@Override
	public double amountToReimburse(){
		return totalCost;
	}
	
	@Override
	public String getDescription()
	{
		return "Took the bus from the " + busLine + " company from " + outboundStartDate + " to " + inboundEndDate;
	}
	
	public LocalDate getoutboundStartDate() {
		return outboundStartDate;
	}
	public LocalDate getinboundEndDate() {
		return inboundEndDate;
	}
	public int sequenceNo(){
		return 3;
	}
	
}
