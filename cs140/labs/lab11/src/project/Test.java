package project;

public class Test
{
	public static void main(String[] args)
	{
		Instruction i1 = new Instruction((byte)0b10000100, 1);
		Instruction i2 = new Instruction((byte)0b11111111, 1);
		Instruction i3 = new Instruction((byte)0b11111110, 1);
		try
		{
			Instruction.checkParity(i1);
			Instruction.checkParity(i2);
			Instruction.checkParity(i3);
			System.out.println("Test failed: ParityCheckException not thrown");
		}
		catch(ParityCheckException e)
		{
			System.out.println(e);
		}
	}
}
