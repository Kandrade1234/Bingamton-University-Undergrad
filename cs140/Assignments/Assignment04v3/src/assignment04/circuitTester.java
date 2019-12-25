package assignment04;

public class circuitTester {

	public static void main (String args[])
	{
		
		ResonantCircuit r0 = new ResonantCircuit(10, 3, 70);
		r0.display();
		
		
		ResonantCircuit r1 = new ParallelResonantCircuit(70, 0.05, 0.07);
		r1.display();
		
		
		ResonantCircuit r3 = new SeriesResonantCircuit(70, 0.05, 0.07);
		r3.display();
		
		
		
		//Zero values
		try{
		ResonantCircuit testParallel = new ParallelResonantCircuit(0, 0.05, 0.07);
		testParallel.display();
			} catch(IllegalArgumentException e){
			System.out.println(e);}
		
		try{
			ResonantCircuit testParallel2 = new ParallelResonantCircuit(70, 0.00, 0.00);
			testParallel2.display();
				} catch(IllegalArgumentException e){
				System.out.println(e);}
			
		
		try{
			ResonantCircuit testSeries = new SeriesResonantCircuit(70, 0.00, 0.07);
			testSeries.display();
				} catch(IllegalArgumentException e){
				System.out.println(e);}
			
		try{
			ResonantCircuit testSeries2 = new SeriesResonantCircuit(70, 0.05, 0.00);
			testSeries2.display();
				} catch(IllegalArgumentException e){
				System.out.println(e);}
		
		
		
		
	}
	
	
	
	
}
