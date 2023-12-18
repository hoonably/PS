import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int sum=1667;
		for(int i=0;i<=1000;i++) {
			for(int j=0;j<=1666;j++) {
				if(5*i+3*j==n) {
					if(i+j<sum) {
						sum = i+j;
					}
				}
			}
		}
		if(sum==1667) {
			System.out.println(-1);
		}
		else {
			System.out.println(sum);
		}
	}

}
