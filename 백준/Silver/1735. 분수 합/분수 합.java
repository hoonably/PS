import java.util.Scanner;

public class Main { // 분수 합

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n1 = sc.nextInt();
		int n2 = sc.nextInt();
		int m1 = sc.nextInt();
		int m2 = sc.nextInt();
		sc.close();
		
		
		int bunja = n1*m2 + n2*m1;
		int bunja1 = n1*m2 + n2*m1;
		int bunmo = n2*m2;
		int bunmo1 = n2*m2;

		int yaksu = 1;
		for(int j=2;j<=100000000;) {
			if(bunja%j==0&&bunmo%j==0) {
				bunja/=j;
				bunmo/=j;
				yaksu*=j;
			}
			else {
				j++;
			}
		}
		bunja1/=yaksu;
		bunmo1/=yaksu;
		System.out.println(bunja1 + " " + bunmo1);
	}

}
