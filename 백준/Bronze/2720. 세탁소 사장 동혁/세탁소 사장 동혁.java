import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		for(int i=0;i<n;i++) {
			int money = sc.nextInt();
			System.out.print(money/25 + " ");
			money%=25;
			System.out.print(money/10 + " ");
			money%=10;
			System.out.print(money/5 + " ");
			money%=5;
			System.out.println(money);
		}
		sc.close();
	}
}
