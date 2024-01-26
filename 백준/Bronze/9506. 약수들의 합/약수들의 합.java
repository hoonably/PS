import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int n = sc.nextInt();
			if(n==-1) {
				break;
			}
			int[] arr = new int[n];
			
			System.out.print(n + " ");
			
			int temp=0;
			for(int i=1;i<n;i++) {
				if(n%i==0) {
					arr[temp]=i;
					temp++;
				}
			}
			
			int sum=0;
			for(int i=0;i<temp;i++) {
				sum+=arr[i];
			}
			
			
			if(sum==n) {
				System.out.print("= ");
				for(int i=0;i<temp;i++) {
					if(i<temp-1) {
						System.out.print(arr[i] + " + ");
					}
					else {
						System.out.print(arr[i]);
					}
				}
				System.out.println();
			}
			else {
				System.out.println("is NOT perfect.");
			}
		}
		sc.close();
		
	}

}
