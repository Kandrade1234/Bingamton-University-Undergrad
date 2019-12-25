import java.util.ArrayList;
public class Ques2 {
	private ArrayList<String> list;
	public Ques2(ArrayList<String> lst) {
		list = lst;
	}
	// FORMAT OF A JAVADOC COMMENT:
	/**
	 * The method will return a list of all strings of length n. (list may be empty i.e size zero)
	 *
	 *
	 * @param int n value will be given to add anything of length n from arraylist to the new arraylist 
	 * @return returns a new array list of values of length n if list is null then it returns null, else returns a list of values of length n 
	 */
	public ArrayList<String> ofLength(int n) {
		ArrayList<String> ret = null;
		if(list != null) {
			ret = new ArrayList<String>();
			for(String s : list) {
				if(s.length() == n) ret.add(s);
			}
		}
		return ret;
	}
}