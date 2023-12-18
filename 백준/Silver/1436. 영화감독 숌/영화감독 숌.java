
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int temp=0;
		for(int i=0;i<=2666799;i++) { //2666799가 10000번째
			String str = Integer.toString(i);
			if(str.contains("666")) {
				temp++;
				if(temp==n) {
					System.out.println(i);
				}
			}
		}
		
	}

}
