import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int n = sc.nextInt();
		sc.close();
		
		String answer ="";
		
		for(int i=30;i>=0;i--) {
			int a=(int) (num/Math.pow(n, i));
			num %=Math.pow(n, i);
			if(a>9) {
				char value_char = (char)(a+'A'-10);
				answer+=value_char;
			}
			else {
				answer+=a;
			}
		}
		int temp=0;
		
		for(int i=0;i<answer.length();i++) {
			if(answer.charAt(i)!='0') {
				temp=i;
				break;
			}
		}
		while(temp<answer.length()) {
			System.out.print(answer.charAt(temp));
			temp++;
		}
	}
}
