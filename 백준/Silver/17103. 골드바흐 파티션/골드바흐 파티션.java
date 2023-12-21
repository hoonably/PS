import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		//1000000이하 소수 배열
		boolean[] under1000000 = new boolean[1000001];
		under1000000[0] = under1000000[1] = true;
		for(int i=2;i<=1000000;i++) {
			// 소수가 아닐경우
            if (!under1000000[i]) {
                for (int j = i + i; j <= 1000000; j += i) {
                    under1000000[j] = true;
                }
            }
		}
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i=0;i<T;i++) {
			int N = sc.nextInt();
			int answer = 0;
			for(int j=2;j<=N/2;j++) {
				if (!under1000000[j] && !under1000000[N - j]) answer++;
			}
			System.out.println(answer);
		}
		sc.close();
	}

}
