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

#define MAX 30'001

int N, M, K;
int parent[MAX];

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if (a>b) parent[a]=b;
    else parent[b] = a;
}

int candy[MAX];
pii group[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=1; i<=N; i++){
        cin >> candy[i];
    }

    // 친구 관계
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // 그룹별로 대표에 캔디 총량 기록
    for(int i=1; i<=N; i++){
        int par = findParent(i);
        group[par].first++;  // 그룹 인원
        group[par].second += candy[i];  // 그룹 캔디 총량
    }

    // 냅색알고리즘
    // K명이 되는순간 공명해서 실패 => K-1까지
    vector<int> dp(K);
    for (int i=1; i<=N; i++){
        if (parent[i]!=i) continue;

        auto [gCnt, gCandy] = group[i];  // 그룹 인원        
        for (int j=K-1; j>=gCnt; j--){
            dp[j] = max(dp[j], dp[j-gCnt] + gCandy);
        }
    }

    cout << dp[K-1];
    
    return 0;
}