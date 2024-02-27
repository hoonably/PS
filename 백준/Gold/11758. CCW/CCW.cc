#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
외적을 통한 넒이 구하기를 이용
CCW는 세 점으로 이루어진 삼각형의 면적을 통해서 판단한다.

공식 :  CCW = (Bx - Ax) * (Cy - Ay) - (Cx - Ax) * (By - Ay) 
CCW 의 값이 양수라면? : 점 C는 선분 AB의 반시계방향에 위치한다.
CCW 의 값이 음수라면? : 점 C는 선분 AB의 시계방향에 위치한다.
CCW 의 값이 0 이라면? : 점 C는 선분 AB의 직선상에 위치한다.
*/

struct coordinate {
    int x;
    int y;
};

int ccw(coordinate p1, coordinate p2, coordinate p3) {
    int s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);

    if (s > 0) return 1;  // 반시계방향
    else if (s == 0) return 0;  //직선
    else return -1;  // 시계방향
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    coordinate P1, P2, P3;
    cin >> P1.x >> P1.y;
    cin >> P2.x >> P2.y;
    cin >> P3.x >> P3.y;
    cout << ccw(P1,P2,P3);
    
    return 0;
}