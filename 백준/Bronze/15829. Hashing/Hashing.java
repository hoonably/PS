import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
			
		final int M = 1234567891;
			
		Scanner sc = new Scanner(System.in);
		long L = sc.nextInt();
		String str = sc.next();
		sc.close();
		long sum = 0;
//		for(int i=0;i<L;i++) {
//			long a = str.charAt(i) - 'a' + 1;
//			sum += a * Math.pow(31, i);
//		}
//		System.out.println(sum);	
		
		
		long pow = 1;
		char[] arr = str.toCharArray();
		for(int i = 0; i < L; i++)
		{
			sum += (arr[i] - 'a' + 1) * pow % M; //분배법칙
			pow = pow * 31 % M; //분배법칙
		}
		long hash = sum % M;
		System.out.println(hash);
	}
}
