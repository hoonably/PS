import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[5];
		int sum = 0;
		for(int i=0;i<5;i++) {
			arr[i] = sc.nextInt();
			sum+=arr[i];
		}
		sc.close();
		bubblesort(arr);

		System.out.println(sum/5);
		System.out.println(arr[2]);
	}
	public static void bubblesort(int[] arr) {
		for(int i=0;i<arr.length;i++) {
			for(int j=0; j < arr.length - i - 1 ; j++) {
				if(arr[j]>arr[j+1]) {
					swap(arr,j,j+1);
				}
			}
		}
	}
	
	public static void swap (int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}

}
