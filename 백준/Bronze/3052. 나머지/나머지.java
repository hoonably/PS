import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[10];
		int temp=0;
		
		for (int i=0;i<10;i++) {
			arr[i] = sc.nextInt();
			arr[i] = arr[i]%42;

		}
		
		for(int j=0;j<42;j++) {
			for(int i=0;i<10;i++) {
				if(arr[i]==j) {
					temp++;
					break;
				}
			}

		}
		
		System.out.println(temp);
		
		
		
		sc.close();
		

	}

}
