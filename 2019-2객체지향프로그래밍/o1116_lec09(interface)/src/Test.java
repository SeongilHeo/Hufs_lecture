
public class Test {
	public static void main(String args[]) {
		Speaker sp =null;//인터페이스 객체지만 참조는 가능
		System.out.println("sp pointing to Politician");
		sp = new Politician();
		sp.speak();
		
		System.out.println("sp pointing to Coach");
		sp = new Coach();
		sp.speak();
		
		System.out.println("sp pointing to Lecturer");
		sp = new Lecturer();
		sp.speak();
	}
}
