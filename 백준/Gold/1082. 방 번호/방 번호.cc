#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 10

int N, M;
int P[MAX];
string dp[51];

string max_(string& s1, string& s2) {
    if (s1.length() > s2.length()) return s1;
    if (s1.length() < s2.length()) return s2;

    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] > s2[i]) return s1;
        if (s1[i] < s2[i]) return s2;
    }
    return s1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> P[i];
    cin >> M;

    for(int i=1; i<=M; i++){
        for (int j = 0; j <= i; ++j) {
            dp[i] = max_(dp[i], dp[j]);
            for (int k = 0; k < N; ++k) {
                if (P[k] <= i - j) {
                string tmp = dp[j] + to_string(k);

                // "0?" 인 경우 "?" 으로 처리
                if (tmp.size() > 1 && tmp[0] == '0') tmp = tmp.substr(1);
                dp[i] = max_(dp[i], tmp);
                }
            }
        }
    }

    cout << dp[M];
    
    return 0;
}