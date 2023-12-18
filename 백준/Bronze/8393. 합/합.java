import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int a = 0;
		while(n>0) {
			a +=n;
			n --;
		}
		System.out.println(a);

	}

}
