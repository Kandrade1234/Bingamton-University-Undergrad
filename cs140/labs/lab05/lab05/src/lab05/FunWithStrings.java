package lab05;
import java.util.ArrayList;
import java.util.Arrays;
public class FunWithStrings{


public static void swapMaxes(ArrayList<String> list1, ArrayList<String> list2)
{
	String hold1 = "";
	int index1 = 0 ;
	
	for (int i =0; i < list1.size(); i++)
	{
			if(list1.get(i) != null)
			{
			   if( list1.get(i).length() > hold1.length())
				{
					hold1 = list1.get(i);
					index1 = i;
				}
			}
	}	
	
	
	String hold2 = "";
	int index2 = 0;
	for (int i =0; i < list2.size(); i++)
	{			
		if(list1.get(i) != null)
			{
			   if( list2.get(i).length() > hold2.length())
				{
					hold2 = list2.get(i);
					index2 = i;
				}
			}
	}

	list1.set(index1, hold2);
	list2.set(index2, hold1);
		
}



}
