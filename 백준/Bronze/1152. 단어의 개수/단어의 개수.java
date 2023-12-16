import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int n =1;
		if(str.charAt(0)==' ') {
			n--;
		}
		if(str.charAt(str.length()-1)==' ') {
			n--;
		}
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)==' ') {
				n++;
			}
		}
		System.out.println(n);

	}

}
