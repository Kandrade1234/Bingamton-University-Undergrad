package assignment05;
import java.time.LocalDate;
public class TravelByRail implements TravelExpenses {

	private LocalDate outboundStartDate;
	private LocalDate inboundEndDate;
	private String railLines; 
	private double totalCost;
	
	
	
	
	public TravelByRail(LocalDate out, LocalDate in, String lines, double totalCost){
		outboundStartDate = out;
		inboundEndDate = in;
		railLines = lines;
		this.totalCost = totalCost;	
	}
	@Override
	public double amountToReimburse(){
		return totalCost;
	}
	
	@Override
	public String getDescription()
	{
		return "Took a train from " + railLines + " from "  + outboundStartDate + " to " + inboundEndDate;
	}
	
	public LocalDate getoutboundStartDate() {
		return outboundStartDate;
	}
	public LocalDate getinboundEndDate() {
		return inboundEndDate;
	}
	public int sequenceNo(){
		return 2;
	}
	
}
