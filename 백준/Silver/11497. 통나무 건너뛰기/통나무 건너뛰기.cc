#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX 10'000

/*
https://www.acmicpc.net/problem/11497
어떻게 풀어야하는지 몰라서 찾아봄
*/

int L[MAX];

void solve(){
    int N;
    cin >> N;

    FOR(i,0,N){
        cin >> L[i];
    }

    sort(L, L+N);

    int result = L[1] - L[0];

    // 짝수 차이
    for (int i = 2; i < N; i+=2) {
        result = max(result, L[i] - L[i-2]);
    }

    // 홀수 차이
    for (int i = 3; i < N; i += 2) {
        result = max(result, L[i] - L[i-2]);
    }
    
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}