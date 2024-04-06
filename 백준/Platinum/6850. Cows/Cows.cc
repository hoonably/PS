#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100000

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기

볼록 껍질을 구한 후, 기준점을 잡고,
각 기준점으로부터 모든 점을 그으면 삼각형이 now-2개 생긴다.
삼각형의 넓이의 합을 50으로만 나누면 정답이다.
*/

struct dot {
    ll x,y;
};

dot P[MAX];
dot CH[MAX];  // Convex Hull

ll ccw(dot a, dot b, dot c) {
    // 양수라면 반시계방향
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool compare(dot a, dot b){ //반시계 정렬
    
    ll cc = ccw(P[0], a, b);
    if (cc) // 0 번 점을 기준으로 각도가 작은 순
        return cc > 0;
    else if (a.y != b.y) //y가 작은 순
        return a.y < b.y;
    else //x가 작은 순
        return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N;
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> P[i].x >> P[i].y;
    }
    
    // y좌표와 x좌표가 가장 작은 점이 P[0]에 오도록 정렬
    for (int i=1; i<N; i++){
        if(P[i].y < P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)){
            swap(P[0].x, P[i].x);
            swap(P[0].y, P[i].y);
        }
    }
    
    sort(P+1, P+N, compare);
    
    // 볼록껍질 검사
    CH[0] = P[0];
    CH[1] = P[1];

    int now = 2;
    for(int i=2; i<N; i++){
        while (now >= 2){
            // 상위 두개의 원소 반시계인지 비교   
            if (ccw(CH[now-2], CH[now-1], P[i]) > 0){
                break;  // 반시계방향이라면 종료
            }
            now--;  // 반시계방향이 아니라면 없애고 계속 탐색
        }
        CH[now] = P[i];
        now++;
    }
    
    double area = 0;
    for (int i=1; i<now-1; i++){
        area += 0.5 * abs(ccw(CH[0], CH[i], CH[i+1]));
    }
    int ans = area / 50;
    cout << ans;
    
    return 0;
}