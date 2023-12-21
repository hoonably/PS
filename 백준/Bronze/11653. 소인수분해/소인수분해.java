
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		while(n!=1) {
			for(int i=2;i<=n;i++) {
				if(n%i==0) {
					n/=i;
					System.out.println(i);
					i--;
				}
			}
		}
		
		

	}

}
