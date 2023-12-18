import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Deque<Integer> deque = new ArrayDeque<>();
		
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int[] arr = new int[N];
		for(int i=0;i<N;i++) {
			deque.addLast(i+1); // 풍선 덱 생성 1~N
			arr[i]=Integer.parseInt(st.nextToken()); // N개의 각 풍선의 정수 입력
		}
		
		int repeat = 1;
		int pop = 0;
		
		while(deque.size()>0) {
			//양수가 적혀있던 경우 + 첫 시작
			if(repeat>0) { 
				for(int i=0;i<repeat-1;i++) {
					int temp = deque.pollFirst();
					deque.addLast(temp);
				}
				pop = deque.pollFirst();
				sb.append(pop).append(" ");
			}
			//음수가 적혀있던 경우
			else { 
				repeat = -repeat;
				for(int i=0;i<repeat-1;i++) {
					int temp = deque.pollLast();
					deque.addFirst(temp);
				}
				pop = deque.pollLast();
				sb.append(pop).append(" ");
			}
			repeat = arr[pop-1];
		}
		System.out.println(sb);
	}
}
