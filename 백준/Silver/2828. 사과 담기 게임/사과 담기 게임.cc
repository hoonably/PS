#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX

/*
N : 떨어질 수 있는 칸의 개수
M : 바구니가 차지하는 크기

문제를 똑바로 안읽고 바구니가 M개 있는줄 알고 어려워했다.
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M, J;
    cin >> N >> M;
    
    int start = 1;
    int end = M;

    int cnt = 0;

    cin >> J;
    while (J--){
        int x;
        cin >> x;

        while(true){
            // 범위 안에 있다면
            if(start<=x && x<=end) break;

            // 시작점보다 이전에 있다면
            else if(x < start) {
                start--; end--; cnt++;
            }

            // 시작점보다 뒤에 있다면
            else {
                start++; end++; cnt++;
            }
        }
    }
    cout << cnt;

    
    return 0;
}