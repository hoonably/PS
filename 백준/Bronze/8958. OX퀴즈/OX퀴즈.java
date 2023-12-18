import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i=0;i<N;i++) {
			String str = sc.next();
			int answer = 0;
			int how = 0;
			for(int j=0;j<str.length();j++) {
				if(str.charAt(j)=='O') {
					how++;
					answer+=how;
				}
				else {
					how=0;
				}
			}
			System.out.println(answer);
		}
		sc.close();
	}

}
