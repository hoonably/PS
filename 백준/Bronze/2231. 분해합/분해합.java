import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		System.out.println(answer(n));
	}
	
	static int answer(int n) {
		for(int i=0;i<n;i++) {
			int temp=0;
			String istr = Integer.toString(i);
			for(int j=0;j<istr.length();j++) {
				temp+=istr.charAt(j)-'0';
				}
			if(temp+i==n) {
				return i;
			}
		}
		return 0;
	}
}
