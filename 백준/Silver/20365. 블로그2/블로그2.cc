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

*/

#define MAX 

int N;
string word;
int R, B;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> word;

    if (word[0] == 'B') B++;
    else R++;

    for (int i = 1; i < N; i++) {
        if (word[i] == 'B' && word[i-1] == 'R') B++;
        if (word[i] == 'R' && word[i-1] == 'B') R++;
    }
    cout << min(R, B) + 1;	// 더 적게 나타나는 색의 개수 + 더 많이 나타나는 색으로 전체를 칠한 수(1)

    return 0;
}