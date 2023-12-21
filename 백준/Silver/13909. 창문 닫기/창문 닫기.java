import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.close();
		
		int answer = 0;
		
		int temp = 1;
		while(temp*temp<=N) {
			answer++;
			temp++;
		}
		
		System.out.println(answer);
	}

}
