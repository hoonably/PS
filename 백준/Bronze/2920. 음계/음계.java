import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		int[] arr = new int[8];
		
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<8;i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		
		int[] ascending = new int[] {1,2,3,4,5,6,7,8};
		int[] descending = new int[] {8,7,6,5,4,3,2,1};
		
		if(Arrays.equals(arr, ascending)) {
			System.out.println("ascending");
		}
		else if(Arrays.equals(arr, descending)) {
			System.out.println("descending");
		}
		else {
			System.out.println("mixed");
		}
		
	}

}
