import java.util.Scanner;

public class Main {
	
	public static void print_prime(int n) {
		
		int[] arr = new int[2*n+1];
		
		for(int i=2;i<=2*n;i++) {
			arr[i] = i;
		}
		
		for(int i=2;i<=2*n;i++) {
			if(arr[i]==0) { //이미 지워진 수라면 건너뛴다.
				continue;
			}
			//건너뛰지 않은 수는 소수이다.
			for(int j=2*i;j<=2*n;j+=i) { // N 전까지 자신을 포함하지 않는 소수의 배수를 모두 지운다.
				arr[j]=0;
			}
			
		}
		int answer = 0;
		for(int i=n+1;i<=2*n;i++) {
			if(arr[i]!=0) {
				answer++;
			}
		}
		System.out.println(answer);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int n = sc.nextInt();
			if(n==0) {
				break;
			}
			else {
				print_prime(n);
			}
		}
		sc.close();
	}

}
