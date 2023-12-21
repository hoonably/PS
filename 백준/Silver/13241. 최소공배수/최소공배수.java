import java.util.Scanner;

public class Main {

	public static long gcd(long a, long b) {
	    if (b == 0) {
	      return a;
	    }
	    return gcd(b, a % b);
	}
	
	public static long lcm(long a, long b) {
	    long gcd = gcd(a, b);
	    return (a * b) / gcd;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		sc.close();
		
		System.out.println(lcm(a, b));
		

	}

}
