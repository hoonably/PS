import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int hour = sc.nextInt();
		int minute = sc.nextInt();
		int after_minute = minute - 45;
		
		if (after_minute>=0) {
			System.out.println(hour + " " + after_minute);
		}
		else if (hour != 0) {
			System.out.println( (hour-1) + " " + (after_minute+60));
		}
		else {
			System.out.println("23 " + (after_minute+60));
		}
	}

}
