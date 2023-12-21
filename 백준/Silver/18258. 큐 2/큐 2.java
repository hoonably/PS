import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		Queue<Integer> queue = new LinkedList<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		
		int N = Integer.parseInt(br.readLine());
		
		// 마지막 값은 queue로 불러올 수 없으니 저장
		int last = 0;
		
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			
			if(str.equals("push")) {
				int a = Integer.parseInt(st.nextToken());
				queue.offer(a);
				last = a;
				
			}
			else if(str.equals("pop")) {
				if(!queue.isEmpty()) {
					bw.write(queue.poll() + "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
			else if(str.equals("size")) {
				bw.write(queue.size() + "\n");
			}
			else if(str.equals("empty")) {
				if(queue.isEmpty()) {
					bw.write(1 + "\n");
				}
				else {
					bw.write(0 + "\n");
				}
			}
			else if(str.equals("front")) {
				if(!queue.isEmpty()) {
					bw.write(queue.element() + "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
			else if(str.equals("back")) {
				if(!queue.isEmpty()) {
					bw.write(last + "\n");
				}
				else {
					bw.write(-1 + "\n");
				}
			}
		}
		
		bw.flush();
	}

}
