package lab04;
import java.util.ArrayList;
import java.util.Arrays;
public class ArrayListPractice
{
	private ArrayList <Integer> arrList = new ArrayList<>();

	public int intRemoveAll(int e)
	{	
		//remove all occurances of e
		//Return number of elements removed

		int counter =0;

		for (int i =0; i < arrList.size(); i++)
		{	
			while(i < arrList.size() && arrList.get(i) == e)
			{
				arrList.remove(i);	
				counter++;
			}	
		}
		return counter; 
	}
	
	public boolean isEqual (ArrayList <Integer> other)
	{
		boolean check = false;
		if (other == null)
			throw new IllegalArgumentException("Null input");
		else if(other.size() == arrList.size())
		{
			check = true;
			for (int i =0; i < arrList.size(); i++)
			{	if(other.get(i) != arrList.get(i))
					check = false;
			}	
			return check;
		}
		else 
			return check;



	}
	public void appendArray (int[] arr)
	{
		if (arr == null)
			throw new IllegalArgumentException("Null input");
		else
		{
		    for (int i =0; i <arr.length; i++)
			{
				arrList.add(arr[i]);
			}
		}
	}
	 

	public  ArrayList <Integer> sumElementWise (ArrayList <Integer> other)
	{

	ArrayList <Integer> temp = new ArrayList<>();
	
	if (other == null)
    	throw new IllegalArgumentException("Null input");

	else if (other.size() <= arrList.size()) 	
	{
		for (int i =0; i < other.size (); i++)
		{	
			int holder = 0;
			holder = other.get(i) + arrList.get(i);
			temp.add(holder); 
		}//for the rest of arrList 
		for (int i = temp.size(); i < arrList.size (); i++)
		{	
			temp.add(arrList.get(i)); 
		}
		
	}
	else if (other.size() > arrList.size())
	{
		for (int i =0; i < arrList.size (); i++)
		{	
			int holder =0;
			holder = other.get(i) + arrList.get(i);
			temp.add(holder);
		}
		for (int i = temp.size(); i < other.size (); i++)
		{	
			temp.add(other.get(i)); 
		}
		
	}
	return temp;

	}

	public ArrayList <Integer> getList()
	{
		return arrList;
	}
		
public static void main(String[] args){
	int[] arr = new int [] {1,1,2,4,5,5};
	
	ArrayListPractice test= new ArrayListPractice();
	test.appendArray(arr);
	//whats inside
	System.out.println("Expected: [1, 1, 2, 4, 5, 5] " + "   Result: " + test.getList());
	
	//removes
	System.out.println("Removing all 1's......");
	
	test.intRemoveAll(1);
	System.out.println("Expected: [2, 4, 5, 5] " + "   Result: " + test.getList());

	System.out.println("\nRemoving all 5's......");
	test.intRemoveAll(5);
	System.out.println("Expected: [2, 4] " + "   Result: " + test.getList());

	
/////////BOOL////////////////////////////////////////////////////////////////////////
	ArrayList<Integer> testArrayList = new ArrayList<>(Arrays.asList(2,4)); //makes new arraylist
	System.out.println("\nExpected: true " + "   Result: " + test.isEqual(testArrayList));

	
	System.out.println("Expected: false " + "   Result: " + test.isEqual(new ArrayList<Integer>(Arrays.asList(2,4,5))));

	try{
	System.out.println(test.isEqual(null)); //return false
	}
	catch (IllegalArgumentException e){
		System.out.println(e); 

	}
	
	System.out.println("Expected: false" +  "   Result: "+  test.isEqual(new ArrayList<Integer>()));

//////////////SUMELEMENT//////////////////////////////////////////////////////////////////////////
	System.out.println("\nAdding [2, 4] + [2,4].....");
	System.out.println("Expected: [4, 8]" + "   Result: " + test.sumElementWise(new ArrayList<Integer>(Arrays.asList(2,4))));
	System.out.println("\nAdding [2, 4] + [2].....");
	System.out.println("Expected: [4, 4]" + "   Result: " + test.sumElementWise(new ArrayList<Integer>(Arrays.asList(2))));
	System.out.println("\nAdding [2, 4] + [2, 4, 5].....");
	System.out.println("Expected: [4, 8, 5]" + "   Result: " + test.sumElementWise(new ArrayList<Integer>(Arrays.asList(2,4,5))));
	
	try{
	System.out.println(test.sumElementWise(null));
	}
	catch (IllegalArgumentException e){
		System.out.println(e); 

	}
/////////////////MoreAppend///////////////////////////////////////////////////////////////////////
	
	
	test.appendArray(new int [] {5,6,7});
    System.out.println("\nAppending [5, 6, 7] to the end of [2, 4];  Expected: [2, 4, 5, 6, 7]  Result: " + test.getList()); 

    System.out.println("Now Adding [2, 4, 5, 6, 7] + [2, 4, 5].....");
	System.out.println("Expected: [4, 8, 10, 6, 7]" + "   Result: " +test.sumElementWise(new ArrayList<Integer>(Arrays.asList(2,4,5))));
	
	try{
		test.appendArray(null);
		}
		catch (IllegalArgumentException e){
			System.out.println(e); 
		}
}
	
	
}


