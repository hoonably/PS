import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//1 2~7 8~19 20~37 38~61
		//1개 6개 12개 18개 24개  이렇게 6개씩 늘어난다.
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		for(int j=1;j<=18258;j++) { //최대인 1,000,000,000일때 18258이다.
			if(j==1) {
				n-=1;
			}
			else {
				n-=6*(j-1);
			}
			if(n<=0) {
				System.out.println(j);
				break;
			}

		}

	}

}
