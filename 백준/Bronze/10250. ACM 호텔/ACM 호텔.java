import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i=0;i<T;i++) {
			int H = sc.nextInt();
//			int W = sc.nextInt();
			sc.nextInt();
			int N = sc.nextInt();
			
			if(N%H==0) {
				System.out.print(H);
				N-=H;
			}
			else {
				System.out.print(N%H);
			}
			
			if(N/H+1<10) {
				System.out.println("0"+(N/H+1));
			}
			else {
				System.out.println(N/H+1);
			}
		}
		sc.close();

	}

}
