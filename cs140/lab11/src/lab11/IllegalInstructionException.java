package lab11;
//check divide by zero exception and this class and see if i need to implement similar to paritycheckexception class
public class IllegalInstructionException extends RuntimeException {
	public  IllegalInstructionException(String msg){
		super(msg);
	}
	
}
