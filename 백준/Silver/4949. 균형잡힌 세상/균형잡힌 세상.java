import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		while(true) {
			
			String str = br.readLine();
			if(str.equals(".")) {
				break;
			}
			if(solve(str)) {
				System.out.println("yes");
			}
			else {
				System.out.println("no");
			}
		}
		

		
	}
	
	public static boolean solve(String str) {
		Stack<Character> stack= new Stack<Character>();
		for(int i=0;i<str.length();i++) {
			char c = str.charAt(i);
			
			if(c=='.') {
				break;
			}
			
			
			
			else if(c=='(') {
				stack.push(c);
			}
			
			else if(c==')'){
				if(stack.isEmpty()) {
					return false;
				}
				if(stack.peek() == '(' ) {
					stack.pop();
				}
				else {
					return false;
				}
			}
			
			else if(c=='{') {
				stack.push(c);
			}
			
			else if(c=='}'){
				if(stack.isEmpty()) {
					return false;
				}
				if(stack.peek() == '{' ) {
					stack.pop();
				}
				else {
					return false;
				}
			}
			
			else if(c=='[') {
				stack.push(c);
			}
			
			else if(c==']'){
				if(stack.isEmpty()) {
					return false;
				}
				if(stack.peek() == '[' ) {
					stack.pop();
				}
				else {
					return false;
				}
			}
			
			
		}
		if(stack.isEmpty()) {
			return true;
		}
		else {
			return false;
		}
		
	}

}
