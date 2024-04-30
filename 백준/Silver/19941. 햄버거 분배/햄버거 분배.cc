#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX

/*
https://www.acmicpc.net/problem/19941

사람은 좌우 K거리 이하의 햄버거를 먹을 수 있음
모든 사람이 먹을 수 있는가?
*/

int N, K;
string bench;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    cin >> bench;

    int cnt = 0;

    for (int i=0; i<N; i++){
        if (bench[i]!='P') continue;
        
        // 먹을 수 있는 햄버거가 있는지
        for (int j=max(0,i-K); j<=min(N-1,i+K); j++){
            if(bench[j]=='H'){
                cnt++;
                bench[j]='X';
                break;
            }
        }
    }

    cout << cnt;
    
    return 0;
}