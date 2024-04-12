#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    
    int cnt = 0;

    // 가장 오른쪽에 남아있는 컵 홀더가 있는지
    bool able = true;
    char seat;
    for (int i=0; i<N; i++){
        cin >> seat;

        // 혼자라면 왼쪽이 비면 왼쪽에, 오른쪽이 비면 오른쪽에 놓기
        if (seat=='S'){
            cnt++;
        }

        // 커플석이라면
        else {
            cin >> seat;
            i++;
            // 왼쪽이 비었을 경우
            if (able) {
                cnt+=2;
                able = false;
            }
            // 왼쪽이 차있는 경우 (오른쪽 사람만 오른쪽에)
            else {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}