import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int answer =0; //소수의 합
		
		for(int i=m;i<=n;i++) { //i는 진행중인 자연수
			boolean habsung = false;
			for(int j=2;j<i;j++) {
				if(i%j==0) { //나눠지는게 있으면 합성수
					habsung=true;
					break;
				}
			}
			if(!habsung&&i!=1) { //i이 1이 아니면서 합성수가 아니라면 출력
				answer+=i;
			}
		}
		
		if(answer==0) {
			System.out.println(-1);
		}
		else {
			System.out.println(answer);
		}
		
		for(int i=m;i<=n;i++) { //i는 진행중인 자연수
			boolean habsung = false;
			for(int j=2;j<i;j++) {
				if(i%j==0) { //나눠지는게 있으면 합성수
					habsung=true;
					break;
				}
			}
			if(!habsung&&i!=1) { //i이 1이 아니면서 합성수가 아니라면 출력
				System.out.println(i);
				break;
			}
		}
		
		sc.close();

	}

}
