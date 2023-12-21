
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[]  arr = new int[n];
		int m = sc.nextInt();
		
		while(m>0) {
			int i = sc.nextInt();
			int j = sc.nextInt();
			int k = sc.nextInt();
			for (int t =i-1; t<j; t++) {
				arr[t]=k;
			}
			m--;
		}
		sc.close();
		
		for (int value: arr) {
			System.out.print(value +" ");
		}

	}

}
