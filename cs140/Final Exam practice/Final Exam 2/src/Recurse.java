public class Recurse{
	public static boolean test(int[] arr, int index) {
		if(arr.length == 0 || index >= arr.length) return false;
		return arr[index]%2==0 || !test(arr, index+1);
	}
	public static void main(String[] args) {
		int[] array = {5,4,3,2,1};
		System.out.println(test(array, 0));
		array = new int[]{4,4,3,3,2};
		System.out.println(test(array, 0));
	}
}