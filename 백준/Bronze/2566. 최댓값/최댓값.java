
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		//[0][0]   [0][1]   [0][2]
		//[1][0]   [1][1]   [1][2]
		
		int[][] arr = new int[9][9];
		int biggest = -1;
		int first = -1;
		int second = -1;
		
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				arr[i][j]=sc.nextInt();
				if(arr[i][j]>biggest) {
					biggest = arr[i][j];
					first = i+1;
					second = j+1;
				}
			}
		}
		System.out.println(biggest);
		System.out.println(first+" "+second);
		sc.close();
		


	}

}
