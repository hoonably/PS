import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] arr = new int[N];
		int[] arr2 = new int[N];
		
		for(int i=0; i<N; i++) {
			arr[i]=arr2[i]=sc.nextInt(); //arr와 arr에 동시에 값 넣기
		}
		sc.close();
		
		//배열 복사
		Arrays.sort(arr2);
		
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		int rank = 0;
		for(int i=0;i<N;i++) {
			if(!map.containsKey(arr2[i])) {
				map.put(arr2[i], rank);
				rank++;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int key : arr) {
			int value = map.get(key); // 원본 배열 원소(key)에 대한 value(rank)를 갖고온다.
			sb.append(value).append(" ");
		}
		System.out.println(sb);
	}
}
