
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[][] arr = new char[5][15];
		for(int i=0;i<5;i++) {
			for(int j=0;j<15;j++) {
				arr[i][j]='-';
			}
		}
		for(int i=0; i<5;i++) {
			String str = sc.nextLine();
			for(int j=0;j<str.length();j++) {
				arr[i][j]=str.charAt(j);
			}
		}
		for(int j=0;j<15;j++) {
			for(int i=0;i<5;i++) {
				if(arr[i][j]!='-') {
					System.out.print(arr[i][j]);
				}
			}
		}

	}

}
