
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int big_x =-10000;
		int small_x =10000;
		int big_y =-10000;
		int small_y =10000;
		for(int i=0;i<n;i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			if(x>big_x) {
				big_x = x;
			}
			if(x<small_x) {
				small_x = x;
			}
			if(y>big_y) {
				big_y = y;
			}
			if(y<small_y) {
				small_y = y;
			}
		}
		sc.close();
		System.out.println((big_x-small_x)*(big_y-small_y));
	}

}
