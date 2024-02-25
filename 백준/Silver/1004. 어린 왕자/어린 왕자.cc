#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
출발점과 도착점을 담고있는 원이 몇개인지 세기
*/

int solve(){
    int x1, y1, x2, y2, cx, cy, r;
    int n;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;

    int cnt=0;
    while(n--){
        cin >> cx >> cy >> r;
        // 두 원의 중심 사이의 거리
        double dist1 = sqrt(pow((x1-cx),2) + pow((y1-cy),2));
        double dist2 = sqrt(pow((x2-cx),2) + pow((y2-cy),2));

        // 원이 출발지점과 끝지점을 둘다 품고있으면 통과 안함
        if (dist1 < r && dist2 < r) {
            continue;
        }
        // 둘중에 하나만 품고있으면 통과해야함
        else if (dist1 < r || dist2 < r){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        cout << solve() << '\n';
    }
    
    return 0;
}