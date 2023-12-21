
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[]  arr = new int[n];
		int m = sc.nextInt();
		
		for(int i=0;i<n;i++) {
			arr[i]=i+1;
		}
		
		while(m>0) {
			int i = sc.nextInt();
			int j = sc.nextInt();
			
			int a = (j-i+2)/2;
			
			if (i==j) {
				a=0;
			}
			for(;a>0;a--) {
				int temp = arr[i-1];
				arr[i-1]=arr[j-1];
				arr[j-1]=temp;
				i++;
				j--;
			}
			m--;
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(arr[i]+" ");
		}

		
		sc.close();
		
		
	}
}
