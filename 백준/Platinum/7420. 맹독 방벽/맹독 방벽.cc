#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 1002

/*
Graham scan 알고리즘을 통한 볼록 껍질 구한 후,
그 점들 사이 거리들의 합에서 꺾일때 각도를 이용해 반지름이 L인 부채꼴의 호의 길이를 모두 더해주면 된다.


여기서 생각지도 못한 점
어차피 볼록 껍질이라면 주변의 호들을 이었다면 그냥 360도가 되므로 각도를 각각 구해줄 필요 없이
반지름이 l인 원의 둘레를 한번만 더해주면 된다.
*/

struct dot {
    ll x,y;
};

double dist(dot A, dot B){
    ll dx = A.x-B.x;
    ll dy = A.y-B.y;
    return sqrt(dx*dx + dy*dy);
}

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
    
    int N, L;
    cin >> N >> L;

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

    // 점 출력
    // cout << "x , y\n";
    // for (int i=0; i<now; i++){
    //     cout << CH[i].x << ' ' << CH[i].y << '\n';
    // }
    
    double ans = 0;

    // 순환을 위해 임시로 옮기기
    CH[now] = CH[0];

    // 볼록 껍질의 각 길이 구하기
    for (int i=0; i<now; i++){
        ans += dist(CH[i], CH[i+1]);
    }

    // 각 호의길이 더해주기 = 원 하나의 둘레 더해주기
    ans += 2 * M_PI * L;
    
    cout << round(ans);
    
    return 0;
}