import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		while (n/4>0) {
			System.out.printf("long ");
			n -= 4;
		}
		System.out.println("int");

	}

}
