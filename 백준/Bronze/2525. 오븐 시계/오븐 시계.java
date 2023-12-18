import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int hour = sc.nextInt();
		int minute = sc.nextInt();
		int take_minute = sc.nextInt();
		
		int sum = 60*hour + minute + take_minute;
		
		int after_hour = sum/60;
		if (after_hour>=24) {
			after_hour -= 24;
		}
		
		int after_minute = sum%60;
		
		System.out.println(after_hour + " " + after_minute);
		

	}

}
