#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX


/*
점프 거리의 0배 ~ 2배 사이는 점프 두번으로 갈 수 있다.
대각선으로 두번 점프로
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cout << fixed;
    cout.precision(10);
    
    int X, Y, D, T;
    cin >> X >> Y >> D >> T;
    
    double dist = sqrt(pow(X, 2) + pow(Y, 2));

    // 점프 1번보다 그냥 가는게 나은 경우
    if (D <= T) {
        cout << dist;
        return 0;
    }

    double ans = 0;

    while (dist > 2*D){
        dist -= D;
        ans += T;
    }

    // 점프 두번 vs 점프 한번 + 남은 만큼 vs 그냥 남은 만큼 가기
    ans += min({2.0*T, T + abs(dist-D), dist});

    cout << ans;

    return 0;
}