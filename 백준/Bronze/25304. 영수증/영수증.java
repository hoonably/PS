import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int total = scan.nextInt();
		int how_many_total = scan.nextInt();
		int our_calculate = 0;
		
		while (how_many_total>0) {
			int price = scan.nextInt();
			int how_many = scan.nextInt();
			our_calculate += price*how_many;
			how_many_total--;
		}
		if (total == our_calculate) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}
