import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] arr = new int[n][2];
		for(int i = 0; i < n; i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}
		sc.close();

		//두가지 인자 받는 sort
		//Arrays.sort(배열, Comparator)
		Arrays.sort(arr, new Comparator<int[]>() {		
			@Override
			public int compare(int[] e1, int[] e2) {
				if(e1[0] == e2[0]) {		// 첫번째 원소가 같다면 두 번째 원소끼리 비교
					return e1[1] - e2[1];
				}
				else {
					return e1[0] - e2[0];
				}
			}
		});

		//람다식 이용
//		Arrays.sort(arr, (e1, e2) -> {
//			if(e1[0] == e2[0]) { //x좌표가 같으면
//				return e1[1] - e2[1];
//			} 
//			else {
//				return e1[0] - e2[0];
//			}
//		}
//		);
		
		for(int i = 0; i < n; i++) {
			System.out.println(arr[i][0] + " " + arr[i][1]);
		}
	}
}
