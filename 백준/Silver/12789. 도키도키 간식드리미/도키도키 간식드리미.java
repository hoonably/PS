import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<Integer> stack = new Stack<Integer>();
		
		
		int N = sc.nextInt();
		int[] arr = new int[N];
		
		for(int i=0;i<N;i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		
		int now_num = 1; //들어가야할 숫자
		int j=0; //줄서있는 순서 0~N-1
		while(now_num<=N) {
			
			//원래 열 다 끝날 경우
			if(j==N) {
//				System.out.println(stack);
				allstack(stack, now_num);
				return;
			}
			
			//원래 열에서 넣을 수 있는지
			if(arr[j]==now_num) {
//				System.out.println("원래 열에서" + now_num + "넣음");
				now_num++;
				j++;
			}
			//스택의 꼭대기에서 넣을 수 있는지
			else if(!stack.isEmpty()&&stack.peek()==now_num) {
//				System.out.println("pop 실행으로" + now_num + "넣음");
				stack.pop();
				now_num++;
			}
			//못넣으면 스택에 저장
			else {
				stack.push(arr[j]);
				j++;
			}
		}
		System.out.println("Nice");
		
		// 10
		// 5 4 3 2 1 6 7 8 9 10
		
		// 2 1 3 인경우 바로 들어갈 수 있기 때문에 Nice다.

	}
	
	public static void allstack(Stack<Integer> stack, int now_num) {
		while(!stack.isEmpty()) {
			if(stack.peek()==now_num) {
				stack.pop();
				now_num++;
			}
			else {
				System.out.println("Sad");
				return;
			}
		}
		System.out.println("Nice");
	}
	

}
