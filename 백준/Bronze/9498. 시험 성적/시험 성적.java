import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		if (a>=90) {
			System.out.println("A");
		}
		else if (a>=80) {
			System.out.println("B");
		}
		else if (a>=70) {
			System.out.println("C");
		}
		else if (a>=60) {
			System.out.println("D");
		}
		else {
			System.out.println("F");
		}
	}

}
