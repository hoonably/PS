import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		double all_hakjum=0;
		double all_grade=0;
		
		
		for(int i=0;i<20;i++) {
			sc.next();
			double hakjum = sc.nextDouble();
			String grade = sc.next();
			if(grade.equals("P")) {
				
			}
			else {
				if(grade.equals("A+")) {
					all_hakjum+=hakjum;
					all_grade+=4.5*hakjum;
				}
				if(grade.equals("A0")) {
					all_hakjum+=hakjum;
					all_grade+=4.0*hakjum;
				}
				if(grade.equals("B+")) {
					all_hakjum+=hakjum;
					all_grade+=3.5*hakjum;
				}
				if(grade.equals("B0")) {
					all_hakjum+=hakjum;
					all_grade+=3.0*hakjum;
				}
				if(grade.equals("C+")) {
					all_hakjum+=hakjum;
					all_grade+=2.5*hakjum;
				}
				if(grade.equals("C0")) {
					all_hakjum+=hakjum;
					all_grade+=2.0*hakjum;
				}
				if(grade.equals("D+")) {
					all_hakjum+=hakjum;
					all_grade+=1.5*hakjum;
				}
				if(grade.equals("D0")) {
					all_hakjum+=hakjum;
					all_grade+=1.0*hakjum;
				}
				if(grade.equals("F")) {
					all_hakjum+=hakjum;
					all_grade+=0.0*hakjum;
				}
			}
		}
		System.out.println(all_grade/all_hakjum);
		sc.close();
	}

}
