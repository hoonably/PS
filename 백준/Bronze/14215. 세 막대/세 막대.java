import java.util.Scanner;

public class Main {

	public static int answer(int biggest, int elsesum) {
		while(biggest>=elsesum) {
			biggest--;
		}
		return biggest+elsesum;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		sc.close();
		if(a>=b&&a>=c) {
			System.out.println(answer(a,b+c));
		}
		else if(b>a&&b>c) {
			System.out.println(answer(b,a+c));
		}
		else {
			System.out.println(answer(c,a+b));
		}

	}

}
