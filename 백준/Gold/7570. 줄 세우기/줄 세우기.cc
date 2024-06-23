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
https://www.acmicpc.net/problem/7570
어떤 아이를 뽑아 앞이나 뒤로 보내서 순서를 1 2 3 4 5 로 맞춰야함

가장 긴 증가하는 부분 수열 알고리즘 사용
dp[i] : i번째까지 가장 긴 증가하는 부분수열의 길이
*/

#define MAX 1'000'001

int N;
int dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        dp[num] = dp[num-1] + 1;
    }

    cout << N - *max_element(dp+1, dp+N+1);

    return 0;
}