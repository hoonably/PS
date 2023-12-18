import java.util.Scanner;

public class Main {

	public static boolean is_prime(long n) {
		for(int j = 2; j <= Math.sqrt(n); j++) {  // √N 까지만 봐도 충분하다.
	        
			// 소수가 아닐경우
			if(n % j == 0) { //약수가 존재
				return false;
			}
		}
		// 위 반복문에서 약수를 갖고 있지 않는경우 소수다.
		return true;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int get = sc.nextInt();
		for(int i=0;i<get;i++) {
			long n = sc.nextLong();
			
			// 0, 1은 소수가 아니므로 예외처리
			if(n<2) {
				System.out.println(2);
				continue;
			}
			
			while(!is_prime(n)) {
				n++;
			}
			System.out.println(n);
		}
		sc.close();
	}

}
