package assignment06;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

public class Menu implements MComp {

	private String name;
	private String description;
	private ArrayList<MComp> comps = new ArrayList<MComp>();
	
	public Menu(String name, String description){
		this.name = name;
		this.description = description;
	}
	
	@Override
	public void add(MComp in){
		comps.add(in);
	}
	
	@Override
	public void remove(MComp mComp){
		comps.remove(mComp);
	}
	@Override
	public MComp getChild(int i){
		return comps.get(i);
	}
	@Override
	public String getName(){
		return name;
	}
	@Override
	public String getDescription(){
		return description;
	}
	@Override
	public Iterator<MComp> iterator(){
		return new CompositeIterator(comps.iterator());
	}
	@Override 
	public void pushToStack(Stack<Iterator<MComp>> stack){
		stack.push(comps.iterator());
	}
	public void print(){
		System.out.println("\n" + getName());
		System.out.println(", " + getDescription());
		System.out.println("----------------------------");
	}
	
	
	
	
}
