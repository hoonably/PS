import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] arr = new int[n];
		for(int i=0;i<n;i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		finding(arr,n, m);
	}
	
	static void finding(int[] arr, int n, int m) {
		int best =0;
		for(int i=0;i<n-2;i++) {
			for(int j=i+1;j<n-1;j++) {
				for(int k=j+1;k<n;k++) {
					int temp = arr[i]+arr[j]+arr[k];
					if(temp==m) {
						System.out.println(temp);
						return;
					}
					if(temp>best&&temp<m) {
						best=temp;
					}
				}
			}
		}
		System.out.println(best);
	}
}
