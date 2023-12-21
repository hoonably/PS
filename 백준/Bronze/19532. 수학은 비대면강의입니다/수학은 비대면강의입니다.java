
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 int a = sc.nextInt();
		 int b = sc.nextInt();
		 int c = sc.nextInt();
		 int d = sc.nextInt();
		 int e = sc.nextInt();
		 int f = sc.nextInt();
		 sc.close();
		 for(int x=-999;x<=999;x++) {
			 for(int y=-999;y<=999;y++) {
				 boolean first = a*x+b*y==c;
				 boolean second = d*x+e*y==f;
				 if(first&&second) {
					 System.out.println(x + " " + y);
					 return;
				 }
			 }

		 }

	}

}
