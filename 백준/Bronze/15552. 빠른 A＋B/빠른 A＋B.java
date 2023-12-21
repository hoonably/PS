import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		
		
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
		int how_much = Integer.parseInt(br.readLine()); //int형변환
		
        StringTokenizer st;
        // StringTokenizer를 선언한 이유는,
        // 요구사항이 입력받을 때 한줄로 받도록 되어있기 때문이다.
        // split처럼 사용할수있다.

        for (int i=0; i<how_much; i++) {
        	st = new StringTokenizer(br.readLine(), " "); // 스페이스바를 기준으로 나누는거
        	
        	int a = Integer.parseInt(st.nextToken());
        	int b = Integer.parseInt(st.nextToken());
        	
        	bw.write(a+b + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
        
	}

}
