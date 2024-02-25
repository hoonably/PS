#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
두 원의 교점의 개수를 구하는 문제다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1==x2 && y1==y2 && r1==r2){
            cout << -1 << '\n';
            continue;
        }

        // 두 원의 중심 사이의 거리
        double dist = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

        // 두 원이 떨어져있는 경우
        if (dist > r1 + r2) {
            cout << 0 << '\n';
        }

        // 두 원이 접하는 경우
        else if (dist == r1 + r2){
            cout << 1 << '\n';
        }

        // 한 원이 다른 원의 내부에 있는 경우
        else if (dist + min(r1,r2) < max(r1,r2)){
            cout << 0 << '\n';
        }

        // 한 원의 내부에서 접하는 경우
        else if (dist + min(r1,r2) == max(r1,r2)){
            cout << 1 << '\n';
        }

        // 일반적으로 두 점에서 접하는 경우
        else {
            cout << 2 << '\n';
        }
    }
    

    
    
    return 0;
}