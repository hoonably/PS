import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		sc.close();
		
		int n = str.length();
		int answer =0;
		
		for(int i=0;i<n;i++) {
			if(i+1<n) {
				if(str.charAt(i)=='c'&&str.charAt(i+1)=='=') {
					i++;
				}
				else if(str.charAt(i)=='c'&&str.charAt(i+1)=='-') {
					i++;
				}
				else if(str.charAt(i)=='d'&&str.charAt(i+1)=='-') {
					i++;
				}
				else if(str.charAt(i)=='l' && str.charAt(i+1)=='j') {
					i++;
				}
				else if(str.charAt(i)=='n' && str.charAt(i+1)=='j') {
					i++;
				}
				else if(str.charAt(i)=='s' && str.charAt(i+1)=='=') {
					i++;
				}
				else if(str.charAt(i)=='z' && str.charAt(i+1)=='=') {
					i++;
				}
			}
			if(i+2<n) {
				if(str.charAt(i)=='d'&&str.charAt(i+1)=='z' && str.charAt(i+2)=='=') {
					i+=2;
				}
			}
			answer++;
		}
		System.out.println(answer);
		

	}

}
