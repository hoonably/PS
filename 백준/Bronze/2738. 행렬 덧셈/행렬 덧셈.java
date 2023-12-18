
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		//[0][0]   [0][1]   [0][2]
		//[1][0]   [1][1]   [1][2]
		
		int[][] arr = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr[i][j]+=sc.nextInt();
			}
		}
		sc.close();
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}

	}

}
