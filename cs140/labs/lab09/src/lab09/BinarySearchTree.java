package lab09;

import java.util.Comparator;
import java.util.ArrayList;
import java.util.List;

/**
 * A class to implement the Binary Search Tree data structure.
 * The structure is generic in the type of Objects it contains.
 * @param <T> the type of the contained elements this structure is to hold
 */
public class BinarySearchTree<T> {
	private Comparator<T> comparator;
	private T data;
	private BinarySearchTree<T> left;
	private BinarySearchTree<T> right;

	/**
	 * Constructs an empty BST with a Comparator
	 * @param comp the Comparator to use to impose an ordering on instances of T
	 */
	public BinarySearchTree(Comparator<T> comp) {
		this.comparator = comp;
	}

	/**
	 * Constructs a BST with data and a Comparator
	 * @param data the data this BST should hold
	 * @param comp the Comparator to use to impose an ordering on instances of T
	 */
	public BinarySearchTree(T data, Comparator<T> comp) {
		this.data = data;
		this.comparator = comp;
	}

	/**
	 * Inserts an element into this BST
	 * @param element the element to insert into this BST
	 */
	public void insert(T element) {
		// TODO
		if(data == null){
			data = element;
			return;
		}
		else if(comparator.compare(element, data) < 0){
			if(left != null)
			{	
				left.insert(element);
			}
			else if (left == null)
			{
				left = new BinarySearchTree<>(element, comparator);
				return; //to save computational power i return here instead of letting it return twoards the end
			}
		}
		else if(comparator.compare(element, data) > 0){
			if(right != null)
			{	
				right.insert(element);
			}
			else if(right == null){
				right = new BinarySearchTree<>(element, comparator);
			}

			return;
		} 

	}

	/**
	 * Searchs for a given element in this BST
	 * @param element the element to search this BST for
	 * @return the element in this BST matching the given element, if found,
	 *         otherwise null if the given element is not in this BST
	 */
	public T find(T element) {
		// TODO
		if(data == null){
			return null;
		}
		if(data == element) return element;
		if(comparator.compare(element, data) < 0)
		{
			if(left != null)
			{
				return left.find(element);
			}

		}
		if(comparator.compare(element , data) > 0)
		{
			if(right!= null)
			{
				return right.find(element);
			}

		}
		return null;
	}

	/**
	 * Gathers all the elements of this BST in order
	 * @return a List holding the elements in this BST in order
	 */
	public List<T> getElements() {
		List<T> list = new ArrayList<>();
		// TODO

		//traverses left
		if(left != null){
			list.addAll(left.getElements());
		}
		list.add(data); // adds the element before reaching a null leaf / adds the root after recursing back up.

		//traverses right
		if(right!= null){
			list.addAll(right.getElements());
		}
		return list;
	}

	/**
	 * Pretty prints the contents of this BST in a horizontal tree-like fashion
	 */
	public void prettyPrint() {
		prettyPrint(0);
	}

	private void prettyPrint(int indentLevel) {
		// TODO
		// print `indentLevel` amount of spaces before printing data on its own line
		//HINT: you will want to do an in order traversal here. (see the Traversal section in the explanation of Binary Trees above)
		// you may use a for loop to print `indentLevel` amount of spaces
		// each time you recurse, you add to indentLevel
		if(left!= null){
			left.prettyPrint(indentLevel+2); //tried matching the output on piazza. I initially did +1 but it looked squashed.


		}
		int i = 0;
		while(i < indentLevel)
		{
			System.out.print(" ");
			i++;
		}
		System.out.print(data + "\n");


		if(right!= null){
			right.prettyPrint(indentLevel+2);	
		}



	}

	/**
	 * A main method supplied for any debugging needs
	 */
	public static void main(String[] args) {
		// Up to you how you use this main method, feel free to change it
		Comparator<Integer> intComp = (i, j) -> i - j; // lambda expression
		BinarySearchTree<Integer> tree = new BinarySearchTree<>(intComp);
		tree.insert(3);
		tree.insert(8);
		tree.insert(1);
		tree.insert(0);
		tree.insert(3);
		tree.insert(9);
		tree.insert(4);
		tree.prettyPrint();

	}
}
