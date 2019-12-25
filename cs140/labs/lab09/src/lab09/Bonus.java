package lab09;

import java.util.Comparator;

public class Bonus {
    
	public static void main(String args[]){
		Comparator<String> strings = (i, j) -> j.length() - i.length();
		BinarySearchTree<String> tree;
		tree = new BinarySearchTree <> (strings);
		
		tree.insert("Hello");
		tree.insert("This");
		tree.insert("is");
		tree.insert("a");
		tree.insert("see");
		tree.prettyPrint();
	
	
	
	
	
	}

    
	
}
