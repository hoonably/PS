#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
세 점이 일직선에 있는 경우를 생각해줘야한다.

CCW(A, B, C) * CCW(A, B, D) < 0    &&
CCW(C, D, A) * CCW(C, D, B) < 0

점 C, D 는 선분AB의 연장선상 직선을 기준으로 
항상 서로 반대편에 존재하고 

점 A, B는 선분CD의 연장선상 직선을 기준으로 
서로 반대편에 존재함으로써 교점이 존재하는 상태로 판단
*/

struct P {
    ll x, y;

    void read() {cin >> x >> y;}

    // 연산자 <= 로 x, y 순으로 bool 반환
    bool operator<=(P const &p1){
        if (x==p1.x){
            return y<=p1.y;
        }
        else return x<=p1.x;
    }

    bool operator==(P const &p1){
        return x==p1.x && y==p1.y;
    }
};

void find_intersection(P A, P B, P C, P D) {
	double px = (A.x * B.y - A.y * B.x) * (C.x - D.x) - (A.x - B.x) * (C.x * D.y - C.y * D.x);
	double py = (A.x * B.y - A.y * B.x) * (C.y - D.y) - (A.y - B.y) * (C.x * D.y - C.y * D.x);
	double p = (A.x - B.x) * (C.y - D.y) - (A.y - B.y) * (C.x - D.x);

    // 평행한 경우
	if (p == 0) {
		// 교점이 하나일 때
		if (B == C && A <= C) cout << B.x << " " << B.y << '\n';
		else if (A == D && C <= A) cout << A.x << " " << A.y << '\n';

        // 교점이 없는 경우
        else return;
	}

    // 교차할때
	else {
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

int ccw(P p1, P p2, P p3) {
    ll s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;

    if (s > 0) return 1;  // 반시계방향
    else if (s == 0) return 0;  //직선
    else return -1;  // 시계방향
}

void isOverlapped(P A, P B, P C, P D) {
    int ans1 = ccw(A, B, C) * ccw(A, B, D); // 선분AB를 기준으로 점 C, 점 D 를 체크하는 부분
    int ans2 = ccw(C, D, A) * ccw(C, D, B); // 선분CD를 기준으로 점 A, 점 B 를 체크하는 부분
    
    // 1. 선분이 일직선이거나 양 끝이 접촉해있을 경우
    if(ans1 == 0 && ans2 == 0){
        if(B <= A) swap(A, B);  // A, B 정렬
        if(D <= C) swap(C, D);  // C, D 정렬

        // 1-1. 일직선인데 한점 or 여러점에서 만남 or 한점에서 이어짐
        if (A <= D && C <= B){
            cout << "1\n";
            find_intersection(A,B,C,D);
        }

        // 1-2. 일직선인데 안만남
        else {
            cout << "0\n";
        }
    }

    // 2. 한 점에서 교차 (CCW가 방향이 모두 다름)
    else if(ans1 <= 0 && ans2 <= 0){
        cout << "1\n";
        find_intersection(A, B, C, D);
    }
    // 3. 교차 안함 (CCW가 같은 방향이 있음)
    else cout << "0\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    P L11, L12, L21, L22;
    L11.read(); L12.read();
    L21.read(); L22.read();

    isOverlapped(L11,L12,L21,L22);
    
    return 0;
}