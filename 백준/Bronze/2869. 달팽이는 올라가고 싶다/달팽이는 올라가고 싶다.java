import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//V<10억
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int v=sc.nextInt();
		sc.close();
		int go = a-b;
		int answer = (v-a)/go; // 마지막 a만큼 가는걸 미리 빼고 나눈 횟수
		int now=go*answer;
		while(true) {
			now+=a;
			answer++;
			if(now>=v) {
				break;
			}
		}
		System.out.println(answer);
		
		
//		//맞았지만 시간초과
//		while(true) {
//			go+=a;
//			if(go>=v) {
//				System.out.println(n);
//				break;
//			}
//			go-=b;
//		}

	}

}
