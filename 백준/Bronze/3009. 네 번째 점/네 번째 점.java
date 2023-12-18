
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[6];
		for(int i=0;i<6;i++) {
			arr[i]=sc.nextInt();
		}
		sc.close();
		
		if(arr[0]==arr[2]) {
			System.out.print(arr[4]+" ");
		}
		if(arr[0]==arr[4]) {
			System.out.print(arr[2]+" ");
		}
		if(arr[2]==arr[4]) {
			System.out.print(arr[0]+" ");
		}
		
		//y좌표
		
		if(arr[1]==arr[3]) {
			System.out.println(arr[5]);
		}
		if(arr[1]==arr[5]) {
			System.out.println(arr[3]);
		}
		if(arr[3]==arr[5]) {
			System.out.println(arr[1]);
		}
		
		
		
	}

}
