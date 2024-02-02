import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			
			if(a==0&&b==0&&c==0) {
				break;
			}
			if(a>=b+c||b>=a+c||c>=a+b) {
				System.out.println("Invalid");
			}
			else if(a==b&&b==c) {
				System.out.println("Equilateral");
			}
			else if((a==b||b==c||c==a)) {
				System.out.println("Isosceles");
			}
			else {
				System.out.println("Scalene");
			}
			
		}
		sc.close();

	}

}
