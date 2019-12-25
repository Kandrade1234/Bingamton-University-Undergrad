package exam02;

import java.util.ArrayList;

public class Recursion {
	public static int collatz(int n){
		if(n == 1)
			return 1;
		else if(n % 2 == 0)
			return n + collatz((n/2));
		else 
			return n + collatz((3*n+1));
	}
	public static int count(ArrayList<Integer> list, int n){

		if(list.size() == 1)
		{
			if (list.get(0) == n) return 1;
			else return 0;
		}
		else 
		{
			if (list.get(0) == n)
			{
				list.remove(0);
				return 1 + count(list, n);
			}
			else
			{
				list.remove(0);
				return 0 + count(list, n);
			}
		}
	}
}