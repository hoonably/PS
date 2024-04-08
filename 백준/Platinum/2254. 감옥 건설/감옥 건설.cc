#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 1001

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기
+ // (Px, Py)가 볼록 다각형 안에 있는지 판단
*/

struct dot {
    ll x,y;
    int idx;
};

int N;
dot cow;
bool used[MAX];
dot P[MAX], temp[MAX];
dot CH[MAX];  // Convex Hull

ll ccw(dot a, dot b, dot c) {
    // 양수라면 반시계방향
    ll ret = a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ret>0) return 1;
    if (ret<0) return -1;
    return 0;
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

bool ConvexHull(){

    // N이 2 이하면 다각형을 만들 수 없음
    if (N<=2) return false;

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

    // (Px, Py)가 볼록 다각형 안에 있는지 판단

    CH[now] = CH[0];  // 순환 위해
    for (int i=0; i<now; i++){
        // 반시계방향이 아니라면 밖 or 선 위에 있는거임
        if (ccw(CH[i], CH[i+1], cow)!=1){
            return false;
        }
    }
    
    // 사용한 담 모두 제거하고 배열 다시 구성하기
    for (int i=0; i<N; i++){
        // 일단 임시복사
        temp[i] = P[i];
    }

    for (int i=0; i<now; i++){
        // 사용한 것 체크
        // cout << CH[i].idx << ' ';
        used[CH[i].idx] = true;
    }
    // cout << endl;

    int idx = 0;
    for (int i=0; i<N; i++){
        // 사용한건 추가 안함
        if (used[temp[i].idx]) {
            continue;
        }
        P[idx++] = temp[i];
    }

    N -= now;  // 사용한만큼 개수 줄이기

    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> cow.x >> cow.y;

    for (int i=0; i<N; i++){
        cin >> P[i].x >> P[i].y;
        P[i].idx = i;
    }
    
    int ans = 0;
    while(ConvexHull()){
        ans++;
    }
    cout << ans;
    
    return 0;
}