
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		int w = sc.nextInt();
		int h = sc.nextInt();
		sc.close();
		
		int[] arr = new int[4];
		//좌
		arr[0] = x;
		//우
		arr[1] = w-x;
		//상
		arr[2] = h-y;
		//하
		arr[3] = y;
		
		int best_way = 1000;
		
		for(int i=0;i<4;i++) {
			if(arr[i]<best_way) {
				best_way = arr[i];
			}
		}
		System.out.println(best_way);
	}

}
