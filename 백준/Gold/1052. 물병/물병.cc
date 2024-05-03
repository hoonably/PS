#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
같은 양의 물병을 합쳐서 K개 이하의 물병으로 만드는 경우
1리터짜리 물병을 사야하는 최소값 구하기


*/

#define MAX 

int N, K;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	cin >> N >> K;
    if (N <= K) {
        cout << "0";
        return 0;
    }

    int tmp;
    for (int i = 0; i < K; i++) {
        tmp = 1;
        while ((N + 1) / 2 > tmp)
            tmp *= 2;
        N -= tmp;

        // K개로 만들 수 있음
        if (K - (i + 1) >= N){
            cout << "0";
            return 0;
        }
    }
    cout << tmp - N << '\n';
    
    return 0;
}