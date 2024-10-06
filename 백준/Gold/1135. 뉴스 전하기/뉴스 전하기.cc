#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;\
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 50

int N;
vector<int> sons[MAX];

int dfs(int now){
    if(sons[now].empty()) return 0;

    // 부하직원 소식 저장
    vector<int> dp_sons;
    for(int son : sons[now]){
        dp_sons.push_back(dfs(son));
    }

    // 최대값 정렬
    sort(dp_sons.begin(), dp_sons.end(), greater<>());

    // 소식이 더 오래 걸릴 부하직원부터 먼저 차례로 소식 전하기
    int ret = 0;
    for(int i=0; i<dp_sons.size(); i++){
        ret = max(ret, dp_sons[i] + i + 1);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    int par;
    cin >> par;
    for(int i=1; i<N; i++) {
        cin >> par;
        sons[par].push_back(i);
    }

    cout << dfs(0) << '\n';
    
    return 0;
}