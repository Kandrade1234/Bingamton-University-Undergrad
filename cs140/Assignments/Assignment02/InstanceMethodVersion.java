package assignment02;

public class InstanceMethodVersion {
	private String string;

	public InstanceMethodVersion(String str) {
		string = str;
	}
	public int countSpaces(){
		// counts the spaces in the field string
		int count = -1;
		if( string != null)
		{
			count = 0 ;
			for (int i = 0; i <string.length(); i++)
			{
				if (string.charAt(i) == ' ')
					count++;
			}
		}
		return count;
	}
	public int countSpaces2() {
		int count = -1;
		if (string != null)
		{
			char[] arr = string.toCharArray();
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



	public String withoutExtraSpaces() {
		String returnVal = null;
		if(string != null) {
		//assign returnVal to str.trim() and the ints len1 and len2 to 0
			returnVal = string.trim();
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


	public String first() {
	String returnVal = null;
	if(string != null)
	{
		 returnVal = string.trim();
		 int i = returnVal.indexOf(' ');
		 if(i >= 0)
			returnVal = returnVal.substring(0, i);
	}
	return returnVal;
	}



	public String rest() {
	String returnVal = null;
	if(string != null) {
		returnVal = string.trim();
		int i = returnVal.indexOf(' ');
		if(i >= 0)
			returnVal = returnVal.substring(i+1).trim();
		else
			returnVal =  "";
		}
		return returnVal;		// returns the remainder of the field string removing the first word
	}


	public String[] splitOnSpaces() {
		InstanceMethodVersion temp = new InstanceMethodVersion(withoutExtraSpaces());
		int len = temp.countSpaces();
		String[] returnVal = null;
		if(len >= 0)
		{
			if(string.trim().length() == 0){
				return returnVal = new String[0];
			}
			else
			{
				returnVal = new String[len+1];
				temp = new InstanceMethodVersion(string.trim());
				for (int i = 0; i < returnVal.length; i++)
				{
					returnVal[i] = temp.first();
					temp = new InstanceMethodVersion(temp.rest());
				}
			}
		}
		return returnVal;

	}
	public int[] strLengths() {
		InstanceMethodVersion temp = new InstanceMethodVersion(string);
		String [] wordArr = temp.splitOnSpaces();
		int [] sizeArr = null;
		if (wordArr != null)
		{
			sizeArr = new int [wordArr.length];
			for (int i = 0; i < sizeArr.length;  i++)
				sizeArr [i] = wordArr[i].length();
		}
		return sizeArr; 	}

}
