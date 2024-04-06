#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100000

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기

주어진 점들을 시계방향으로 정렬하고, 정렬된 순서대로 점들을 탐색한다.

이 문제는 첫 시작을 y가 크고 x가 작은점으로,
또한 진행도 시계방향을 원해서 다 거꾸로 해주었다.

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

ll dist(dot a, dot b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool compare(dot a, dot b){ //반시계 정렬
    
    ll cc = ccw(P[0], a, b);
    if (cc) // 0 번 점을 기준으로 각도가 작은 순
        return cc < 0;
    return dist(P[0], a) < dist(P[0], b);  // 거리에 따라
}

void solve(){
    int N;
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> P[i].x >> P[i].y;
    }
    
    // y좌표가 가장 크고 같다면 x좌표가 가장 작은 점이 P[0]에 오도록
    for (int i=1; i<N; i++){
        if(P[i].y > P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)){
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
            // 상위 두개의 원소 시계방향인지 비교   
            if (ccw(CH[now-2], CH[now-1], P[i]) < 0){
                break;  // 시계방향이라면 종료
            }
            now--;  // 시계방향이 아니라면 없애고 계속 탐색
        }
        CH[now] = P[i];
        now++;
    }
    
    cout << now << '\n';
    for (int i=0; i<now; i++){
        cout << CH[i].x << ' ' << CH[i].y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int P;
    cin >> P;
    while(P--){
        solve();
    }
    
    return 0;
}