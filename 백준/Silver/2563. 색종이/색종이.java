import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] arr = new int[100][100];
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int first = sc.nextInt();
			int second = sc.nextInt();
			for(int j=first;j<first+10;j++) {
				for(int k=second;k<second+10;k++) {
					arr[j][k]=1;
				}
			}
		}
		sc.close();
		
		int answer=0;
		
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(arr[i][j]==1) {
					answer++;
				}
			}
		}
		System.out.println(answer);

	}

}
