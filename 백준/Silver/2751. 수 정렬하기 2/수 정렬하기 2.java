import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		int N =	Integer.parseInt(br.readLine());
		for(int i=0; i<N; i++) {
			list.add(Integer.parseInt(br.readLine()));
		}
		
		//오름차순 정렬
		Collections.sort(list);
		
		//StringBuilder 사용
		StringBuilder sb = new StringBuilder();
		
		//향상된 for문 사용
		for(int value : list) {
			sb.append(value).append('\n');
		}
		
		//StringBuilder 출력
		System.out.println(sb);	
		
	}

}