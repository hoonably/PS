#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100001

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기
볼록껍질을 구한 후, 볼록껍질끼리만 비교를 해주면 된다.

* 볼록껍질 순서를 반시계방향으로 함.

회전하는 캘리퍼스 알고리즘
1. 기준점 a를 정하고 다음 점 c를 정함
2. a에서 반시계방향으로 한칸 간 점이 b, c에서 반시계방향으로 한칸 간 점이 d

3~4 단계 반복
3. 벡터 ab 와 벡터 cd를 외적(ccw)했을때 양수(반시계 방향)라면 c를 다음으로
4. 반대로 음수(시계방향) 이면 더이상 가봤자 줄기 때문에 a를 다음 단계로

이 문제는 비스켓을 넣어야 하므로 최대 거리 중에 최소값을 구하면 된다.
*/

struct dot {
    ll x,y;
};

int N;
int Case = 1;
dot P[MAX];
dot CH[MAX];  // Convex Hull

double distSq(dot a1, dot a2, dot b) {
    // 외적을 이용한 벡터와 점 사이의 거리 
    dot c, d;
    c.x = b.x-a1.x, c.y = b.y-a1.y;
    d.x = a2.x-a1.x, d.y = a2.y-a1.y;
    return 1.0 * (c.x*d.y-c.y*d.x)*(c.x*d.y-c.y*d.x) / (d.x*d.x+d.y*d.y);
}

ll ccw(dot a, dot b, dot c) {
    // 양수라면 반시계방향
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

ll ccw2(dot A1, dot A2, dot B1, dot B2){
    // 선분 A , 선분 B 외적
    return (A2.x-A1.x)*(B2.y-B1.y) - (A2.y-A1.y)*(B2.x-B1.x);
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

void solve(){

    for (int i=0; i<N; i++){
        cin >> P[i].x >> P[i].y;
    }
    
    // y좌표와 x좌표가 가장 작은 점이 P[0]에 오도록 변경
    for (int i=1; i<N; i++){
        if(P[i].y < P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)){
            swap(P[0], P[i]);
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
    
    // 회전하는 캘리퍼스 구하기
    double ans = DBL_MAX;  // 불필요한 연산 방지를 위해 일단 제곱으로 저장 후 나중에 루트 씌우기
    int C = 1;
    for (int A=0; A<now; A++){
        // 양수(반시계 방향)라면 C를 높이기
        while(ccw2(CH[A], CH[(A+1)%now], CH[C], CH[(C+1)%now])>0){
            C = (C+1)%now;
        }
        // 시계방향이 된다면 더이상 C를 높여봤자 작아짐
    
        ans = min(ans, distSq(CH[A], CH[(A+1)%now], CH[C]));
    }

    ans = sqrt(ans);
    ans *= 100;
    if (ans - (ll)ans > (1e-12)) {
        ans += 1;
        ans = (ll)ans;
    }
    ans /= 100;
    cout << "Case " << Case++ << ": ";
    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    while(true){
        cin >> N;
        if (N==0) break;
        solve();
    }
    
    return 0;
}