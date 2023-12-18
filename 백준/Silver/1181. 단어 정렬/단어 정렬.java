import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] arr = new String[n];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.next();
		}
		sc.close();

		//두가지 인자 받는 sort
		//Arrays.sort(배열, Comparator)
		Arrays.sort(arr, new Comparator<String>() {		
			@Override
			public int compare(String s1, String s2) {
				//단어 길이가 같은 경우
				if(s1.length() == s2.length()) {
					return s1.compareTo(s2);
					// compareTo
					//s1>s2면 1 반환
					//s1=s2면 0 반환
					//s1<s2면 -1 반환
				}
				else {
					return s1.length()-s2.length(); 
					//s1이 더 길면 양수가 되므로 두 객체의 위치가 바뀐다.
				}
			}
		});
		
		//중복되는 단어는 버리고 출력해야한다.
		for(int i = 0; i < n; i++) {
			if( i>0 && arr[i].equals(arr[i-1]) ) {
				continue;
			}
			System.out.println(arr[i]);
		}
	}
}
