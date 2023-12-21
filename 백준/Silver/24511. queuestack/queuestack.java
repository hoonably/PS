import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] i_gujo = new int[N];
		
		
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		for (int i=0;i<N;i++) {
			i_gujo[i] = Integer.parseInt(st1.nextToken());
		}
		
		
		Deque<Integer> deque = new ArrayDeque<>();
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		
		//어차피 큐인 부분만 영향이 있기 때문에 스택인 부분은 버려도 된다.
		for (int i=0;i<N;i++) {
			int num = Integer.parseInt(st2.nextToken());
			if(i_gujo[i]==0) {
				deque.addLast(num); 
			}
		}

		int M = Integer.parseInt(br.readLine());
		StringTokenizer st3 = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
        for(int i=0; i<M; i++) {
        	//큐인 부분 바꾸는 과정
            deque.addFirst(Integer.parseInt(st3.nextToken()));
            sb.append(deque.pollLast()+" ");
        }
		System.out.println(sb);
		
	}

}
