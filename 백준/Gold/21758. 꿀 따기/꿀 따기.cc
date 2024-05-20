#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/21758

*/

#define MAX 100'001

int A[MAX], S[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, start, mid, end;
    cin >> N;

    int mini = 1e9;
    FOR(i, 1, N+1){
        cin >> A[i];
        mini = min(mini, A[i]);
    }
    FOR(i, 1, N+1){
        S[i] = S[i-1] + A[i];
    }

    int ans = 0;

	// 1. 벌 - 꿀통 - 벌
	for (int i = 2; i < N; i++) {
		int Cur = (S[i] - S[1]) + (S[N - 1] - S[i - 1]);
		ans = max(ans, Cur);
	}

	// 2. 벌 - 벌 - 꿀통
	for (int i = 2; i < N; i++) {
		int Cur = (S[N] - S[1] - A[i]) + (S[N] - S[i]);
		ans = max(ans, Cur);
	}

	// 3. 꿀통 - 벌 - 벌
	for (int i = 2; i < N; i++) {
		int Cur = (S[N - 1] - A[i]) + S[i - 1];
		ans = max(ans, Cur);
	}

    cout << ans;

    return 0;
}