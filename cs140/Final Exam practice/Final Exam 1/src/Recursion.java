public class Recursion {
	int[] array;
	public Recursion(int[] array) {
		if(array == null || array.length == 0) {
			throw new IllegalArgumentException();
		}
		this.array = array;
	}
	public int odd(int index) {
		if(index < 0) {
			throw new IllegalArgumentException();
		}
		if(index == 0 && array.length % 2 == 0) {
			return even(index);
		}
		if(index < array.length) {
			return even(index+1) - array[index];
		}
		return 0;
	}
	public int even(int index) {
		if(index < 0) {
			throw new IllegalArgumentException();
		}
		if(index == 0 && array.length % 2 != 0) {
			return odd(index);
		}
		if(index < array.length) {
			return odd(index+1) + array[index];
		}
		return 0;
	}
	public static void main(String[] args) {
		System.out.println(new Recursion(new int[]{1,2,-3,-4}).odd(0));
		System.out.println(new Recursion(new int[]{-4,2,-3}).odd(0));
	}
}