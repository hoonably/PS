import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		Deque<Integer> deque = new ArrayDeque<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		for(int i=0;i<N;i++) {
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			
			if(M==1) {
				int x = Integer.parseInt(st.nextToken());
				deque.addFirst(x);
			}
			else if(M==2) {
				int x = Integer.parseInt(st.nextToken());
				deque.addLast(x);
			}
			else if(M==3) {
				if(!deque.isEmpty()) {
					bw.write(deque.pollFirst()+ "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
			else if(M==4) {
				if(!deque.isEmpty()) {
					bw.write(deque.pollLast()+ "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
			else if(M==5) {
				bw.write(deque.size() + "\n");
			}
			else if(M==6) {
				if(deque.isEmpty()) {
					bw.write(1 + "\n");
				}
				else {
					bw.write(0 + "\n");
				}
			}
			else if(M==7) {
				if(!deque.isEmpty()) {
					bw.write(deque.peekFirst() + "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
			else if(M==8) {
				if(!deque.isEmpty()) {
					bw.write(deque.peekLast() + "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
			
		}
		
		bw.flush();
		
	}

}
