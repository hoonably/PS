import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		char[][] arr = new char[n][m];
		for(int i=0;i<n;i++) {
			String str = sc.next();
			for(int j=0;j<m;j++) {
				arr[i][j]=str.charAt(j);
			}
		}
		sc.close();
		int best = answer(arr,0,0); //[0][0] [7][7] 까지 첫 시도
		for(int i=0;i<=n-8;i++) {
			for(int j=0;j<=m-8;j++) {
				if(answer(arr,i,j)<best) {
					best=answer(arr,i,j);
				}
			}
		}
		System.out.println(best);
		
	}
	
	
	public static int answer(char[][] arr, int n, int m) { //[n][m]이 시작지점
		int answer1=0; 		//시작이 B인 경우
		int answer2=0;     //시작이 W인 경우


		for(int i=n;i<n+8;i++) {
			for(int j=m;j<m+8;j++) {

				if((i+j)%2==0) { 			//합이 짝수 (시작점포함)
					if(arr[i][j]!='B') {
						answer1++;
					}
					else {
						answer2++;
					}
				}
				else {							//합이 홀수
					if(arr[i][j]!='W') {
						answer1++;
					}
					else {
						answer2++;
					}
				}
			}
		}
		
		if(answer1>answer2) {
			return answer2;
		}
		else {
			return answer1;
		}
	}

}
