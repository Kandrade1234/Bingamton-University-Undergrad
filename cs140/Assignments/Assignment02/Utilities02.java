package assignment02;
import java.util.Optional;
import java.util.Arrays;

public class Utilities02 {
	
public static int countNulls(Object[] array)
{
	int count = 0;
	if (array == null)
		return 0;
	else if (array.length == 0 ){
		return 0;
	}
	else 
	{
		for (int i = 0; i <  array.length; i++)
		{
			if (array[i] == null)
					++count;
		}
	}
	return count;

}

public static int countSpaces(String str)
{
	int count = -1;
	if(str != null) {
		count = 0;
		for (int i = 0; i <  str.length(); i++)
		{
			if (str.charAt(i) == ' ')
				++count;
		}
	}
	return count;	
}

public static int countSpaces2(String str)
{/**ask if we can infer that the string will always not be null 
  if null should we do something like previous count?**/
	int count = -1;
	if (str != null)
	{
		char[] arr = str.toCharArray();
		count = 0 ;
		for (int i = 0; i <  arr.length; i++)
		{
			if (arr[i] == ' ')
				++count;
		}
		return count; 
	}
return count;
}

public static String first(String str)
{
	String returnVal = null;
	if(str != null) 
	{
		 returnVal = str.trim();
		 int i = returnVal.indexOf(' ');	
		 if(i >= 0)
			returnVal = returnVal.substring(0, i);
	}
	return returnVal;	
}

public static String rest(String str) 
{
	String returnVal = null;
	if(str != null) {
		returnVal = str.trim();
		int i = returnVal.indexOf(' ');	
		if(i >= 0)
			returnVal = returnVal.substring(i+1).trim();
		else 
		    returnVal =  "";
	}
	return returnVal;	
}

public static String withoutExtraSpaces(String str)
{
	
	String returnVal = null;
	if(str != null) {
	//assign returnVal to str.trim() and the ints len1 and len2 to 0
		returnVal = str.trim();
		int len1 = 0;
		int len2 = 0;
	//in a do { ... } while(len2 < len1);
	//execute set len1 to the length of returnVal, change returnVal to returnVal.replace("  ", " ")
	//and set len2 to the length of the new returnVal
		do {
			len1 = returnVal.length(); 
			returnVal = returnVal.replace("  "," ");
			len2 = returnVal.length();	
		} while (len2 < len1);
	}
	return returnVal;	
}

public static String[] splitOnSpaces(String str)
{
	int len = countSpaces(withoutExtraSpaces(str));
	String[] returnVal = null;
	if(len >= 0) 
	{
		if(str.trim().length() == 0){
			return returnVal = new String[0];
		}
		else 
		{
			returnVal = new String[len+1];
			for (int i = 0; i < returnVal.length; i++)
			{
				returnVal[i] = first(str);
				str = rest(str);
			}
		}
	}
	return returnVal;
	
}

public static int[] strLengths(String str)
{
	String [] wordArr = splitOnSpaces(str);
	int [] sizeArr = null; 
	if (wordArr != null)
	{
		sizeArr = new int [wordArr.length];
		for (int i = 0; i < sizeArr.length;  i++)
			sizeArr [i] = wordArr[i].length();  
	}
	return sizeArr;      
}

public static Optional<String[]> splitOnSpaces1(String str)
{
	String[] returnVal = null;
	if (str != null && str.trim().length() > 0) {
		returnVal = new String[str.length()];
		int index = 0;
		while (str.length() != 0 )
		{
			returnVal[index] = first(str);
			str = rest(str);
			index++;
		}
		returnVal = Arrays.copyOf(returnVal, index);
		return Optional.of(returnVal);
	}
	else return Optional.empty();
	
	
	
	
	
}



}





