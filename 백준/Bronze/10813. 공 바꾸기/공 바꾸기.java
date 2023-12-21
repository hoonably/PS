import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[]  arr = new int[n];
		for (int i=0;i<arr.length;i++) {
			arr[i]=i+1;
		}
		
		int m = sc.nextInt();
		
		while(m>0) {
			int i = sc.nextInt()-1;
			int j = sc.nextInt()-1;
			int temp =arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			m--;
		}
		
		for (int value: arr) {
			System.out.print(value +" ");
		}
		
		sc.close();
		
		
	}

}
