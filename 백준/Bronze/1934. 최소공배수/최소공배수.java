import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i=0;i<T;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int yaksu = 1;
			for(int j=2;j<=10000;) {
				if(a%j==0&&b%j==0) {
					a/=j;
					b/=j;
					yaksu*=j;
				}
				else {
					j++;
				}
			}
			System.out.println(a*b*yaksu);
		}
		sc.close();
	}

}
