import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int n = sc.nextInt();
		sc.close();
		
		int answer=0;
		
		for(int i=0;i<str.length();i++) {
			int a =0;
			
			if(str.charAt(i)>='A') {
				a =str.charAt(i)-'A'+10;
			}
			else {
				a =str.charAt(i)-'0';
			}
			answer+=a*Math.pow(n, str.length()-i-1);
		}
		System.out.println(answer);
	}

}
