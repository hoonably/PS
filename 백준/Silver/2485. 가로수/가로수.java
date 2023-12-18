import java.util.Scanner;

public class Main {

	public static int gcd(int a, int b) {
	    if (b == 0) {
	      return a;
	    }
	    return gcd(b, a % b);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] tree = new int[N];
		for(int i=0;i<N;i++) {
			tree[i]=sc.nextInt();
		}
		sc.close();

		int gcd = 0;
		for(int i=0;i<N-1;i++) {
			int distance = tree[i+1]-tree[i];
			gcd = gcd(distance, gcd); //원래의 최대공약수와 거리의 최대공약수
		}
		
		//총 가로등 거리
		int all_length = tree[N-1]-tree[0];
		//총 갯수
		int all = all_length/gcd + 1;
		
		
		System.out.println(all-N);
		
		
	}

}
