import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a1 = sc.nextInt();
		int a0 = sc.nextInt();
		int c = sc.nextInt();
		int n0 = sc.nextInt();
		sc.close();
		//f(n) = a1*n+a0
		//g(n) = n
		//c*g(n) = c*n
		//f(n) ≤ c × g(n) 이면 1출력
		if(a1==c) { //일차항이 지워짐 -> n상관 없음
			if(a0<=0) {
				System.out.println(1);
			}
			else {
				System.out.println(0);
			}
		}
		else if(a1>c) { //n이 무한하게 커지면 무조건 불가능
			System.out.println(0);
		}
		else { //n0값에 따라 가능
			if(a1*n0+a0<=c*n0) {
				System.out.println(1);
			}
			else {
				System.out.println(0);
			}
		}

		
		
	}

}
