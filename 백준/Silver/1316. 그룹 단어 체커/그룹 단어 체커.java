
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		int answer=0;
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			String str = sc.next();
			answer++;
			int[] arr = new int[26];
			for(int j=0;j<str.length();j++) {
				if(arr[str.charAt(j)-'a']==0) {
					arr[str.charAt(j)-'a']++;
				}
				else if(str.charAt(j)==str.charAt(j-1)) {
					arr[str.charAt(j)-'a']++;
				}
				else {
					answer--;
					break;
				}
			}
		}
		System.out.println(answer);
        sc.close();

	}

}
