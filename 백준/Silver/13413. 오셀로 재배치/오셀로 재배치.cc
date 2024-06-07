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
https://www.acmicpc.net/problem/13413
*/

#define MAX 

int T;
int N;
string s, e;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    while(T--){
        int w=0, b=0;
        cin >> N >> s >> e;
        for (int i = 0; i < N; i++) {
			if (s[i] == e[i]) continue;
			else { //글자가 다를 때
				if (s[i] == 'B') b++;
				else w++;				
			}
		}

		cout << max(w,b) << '\n';
    }
    
    return 0;
}