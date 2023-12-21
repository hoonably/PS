import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		sc.close();
		System.out.println(n*(n-1)*(n-2)/6);
		System.out.println(3);

	}

}
