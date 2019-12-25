package lab11;

public class Test {
	 public static void main(String[] args){
			Instruction test = new Instruction((byte) 1001,10);
			Instruction.checkParity(test);
			/* UNCOMENT THIS TO THROW EXCEPTION
			Instruction test2 = new Instruction((byte) 1101,10);
			Instruction.checkParity(test2);
			 */
	 }
}
