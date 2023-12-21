import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		Stack<Integer> stack= new Stack<Integer>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			
			int order =  Integer.parseInt(st.nextToken());
			
			if(order == 1) {
				stack.push( Integer.parseInt(st.nextToken()));
			}
			else if(order==2){
				if(stack.isEmpty()) {
					bw.write(-1 + "\n");
				}
				else {
					bw.write(stack.pop() + "\n");
				}
			}
			else if(order==3){
				bw.write(stack.size() + "\n");
			}
			else if(order==4){
				if(stack.isEmpty()) {
					bw.write(1 + "\n");
				}
				else {
					bw.write(0 + "\n");
				}
			}
			else if(order==5){
				if(stack.isEmpty()) {
					bw.write(-1 + "\n");
				}
				else {
					bw.write(stack.peek() + "\n");
				}
			}
		}
		bw.flush();
		
	}

}
