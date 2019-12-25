public class Question2 {

	public static void main(String[] args) {
		Parent p = new Parent(3);
		System.out.println(p.test());
		p = new Child (2,1);
		System.out.println(p.test());
		p = new Grandchild(2,2,1);
		System.out.println(p.test());
	}
}