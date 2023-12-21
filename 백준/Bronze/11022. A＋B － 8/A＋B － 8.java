import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test_case = sc.nextInt();
		for (int i=1; i <= test_case; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int sum = a+b;
			System.out.printf("Case #"+ i + ": " + a + " + " + b + " = " + sum +"\n");
			
		}
		
		sc.close();
	}

}
