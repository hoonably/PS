#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
N개의 소의 효율이 나옴
K개의 연속된 소까지 선택 가능하고 K+1개 연속해서 못 고름
최고 효율합은?

ex)
N=7 / K=2
1, 2, 3, 4, 5, 6, 7
1, x, 3, 4, x, 6, 7 선택

mini[i] : i-K+1번째 ~ i번째 최소값
dp[i] : i-K+1번째 ~ i번째 최고의 효율

dp[i] = max(S[i] - S[j] + dp[j - 1]) ( i - K <= j <= i )
*/

#define MAX 100'001

int N, K;
deque<int> dq;
int A[MAX];
ll S[MAX];
ll dp[MAX];

// 구간합에서 빼주는 값
ll f(int i){
    return S[i] - dp[i-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    // 배열 받기, 연속합 생성
    for (int i=1; i<=N; i++){
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }
    
    for (int i=1; i<=N; i++){
        // 첫번째 인덱스가 지금꺼 -K이면 지움
        if (!dq.empty() && dq.front() < i-K){
            dq.pop_front();
        }
        while (!dq.empty()){
            // 새로 넣는 것보다 크다면
            if (f(dq.back()) > f(i)){
                dq.pop_back();
            }
            else break;
        }
        dq.push_back(i);

        // K개 미만이라면
        if (i<=K) dp[i] = S[i];

        // K개 초과라면 빼야함
        // 현재 i-K ~ i 번중에서 
        // 뺐을때 가장 작은 값이 f(dq.front());
        else dp[i] = S[i] - f(dq.front());
    }

    cout << dp[N];
    
    return 0;
}