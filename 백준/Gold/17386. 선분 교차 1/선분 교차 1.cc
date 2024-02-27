#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
CCW(A, B, C) * CCW(A, B, D) < 0    &&
CCW(C, D, A) * CCW(C, D, B) < 0

점 C, D 는 선분AB의 연장선상 직선을 기준으로 
항상 서로 반대편에 존재하고 

점 A, B는 선분CD의 연장선상 직선을 기준으로 
서로 반대편에 존재함으로써 교점이 존재하는 상태로 판단
*/

struct coordinate {
    ll x;
    ll y;

    void read() {cin >> x >> y;}
};

int ccw(coordinate p1, coordinate p2, coordinate p3) {
    ll s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;

    if (s > 0) return 1;  // 반시계방향
    else if (s == 0) return 0;  //직선
    else return -1;  // 시계방향
}

bool isOverlapped(coordinate A, coordinate B, coordinate C, coordinate D) {
    int ans1 = ccw(A, B, C) * ccw(A, B, D); // 선분AB를 기준으로 점 C, 점 D 를 체크하는 부분
    int ans2 = ccw(C, D, A) * ccw(C, D, B); // 선분CD를 기준으로 점 A, 점 B 를 체크하는 부분
    // 둘다 음수일 경우 교차하는 선분임
    return (ans1 < 0) && (ans2 < 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    coordinate L11, L12, L21, L22;
    L11.read(); L12.read();
    L21.read(); L22.read();

    if (isOverlapped(L11,L12,L21,L22)) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    
    return 0;
}