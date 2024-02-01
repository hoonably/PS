import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		
		// 2 3 5 9
		int line = (int)Math.pow(2, n)+1;
		System.out.println((int)Math.pow(line,2));

	}

}
