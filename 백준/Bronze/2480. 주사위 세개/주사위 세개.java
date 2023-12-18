import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int money = 0;
		
		if (a==b&& b==c) {
			money = 10000 + a*1000;
		}
		else if (a==b || a==c) {
			money = 1000 + a*100;
		}
		else if (b==c) {
			money = 1000 + c*100;
		}
		else {
			if (a>=b) {
				if (a>=c) {
					money = a*100;
				}
				else {
					money = c*100;
				}
			}
			else {
				if (b>=c) {
					money = b*100;
				}
				else {
					money = c*100;
				}
			}
		}
		
		System.out.println(money);
	}

}
