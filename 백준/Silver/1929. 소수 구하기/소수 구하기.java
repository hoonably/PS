import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		sc.close();
		
		int[] arr = new int[N+1];
		
		for(int i=2;i<=N;i++) {
			arr[i] = i;
		}
		
		for(int i=2;i<=N;i++) {
			if(arr[i]==0) { //이미 지워진 수라면 건너뛴다.
				continue;
			}
			//건너뛰지 않은 수는 소수이다.
			for(int j=2*i;j<=N;j+=i) { // N 전까지 자신을 포함하지 않는 소수의 배수를 모두 지운다.
				arr[j]=0;
			}
			
		}
	
		for(int i=M;i<=N;i++) {
			if(arr[i]!=0) {
				System.out.println(arr[i]);
			}
		}

	}

}
