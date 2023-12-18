import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = n;
		for (;n>0;n--) {
			for (int i=m; i>=n; i--) {
				System.out.printf("*");
			}
			System.out.println();
		}
		sc.close();
	}

}
