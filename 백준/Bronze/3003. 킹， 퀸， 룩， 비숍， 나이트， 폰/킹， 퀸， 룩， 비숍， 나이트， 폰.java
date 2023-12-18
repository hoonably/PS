import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int[] good = {1,1,2,2,2,8};
		int[] user = new int[6];
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<6;i++) {
			user[i]= sc.nextInt();
		}
		for(int i=0;i<6;i++) {
			int minus = good[i]-user[i];
			System.out.print(minus + " ");
		}

	}

}
