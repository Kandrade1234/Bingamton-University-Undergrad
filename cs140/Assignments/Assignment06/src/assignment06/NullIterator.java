package assignment06;

import java.util.Iterator;

public class NullIterator implements Iterator<MComp> {


	public MComp next(){
		return null;
	}

	public boolean hasNext(){
		return false;
	}
	
	
	public void remove(){
		throw new UnsupportedOperationException();
	}
	
	


}
