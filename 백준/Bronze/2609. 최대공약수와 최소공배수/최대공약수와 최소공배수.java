import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		int yaksu = 1;
		for(int i=2;i<=10000;) {
			if(a%i==0&&b%i==0) {
				a/=i;
				b/=i;
				yaksu*=i;
			}
			else {
				i++;
			}
		}
		System.out.println(yaksu);
		System.out.println(a*b*yaksu);
		
	}

}
