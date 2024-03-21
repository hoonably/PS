#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 10001


/*
최대 독립집합 : 인접한 정점은 포함되지 않은 최대 가중치를 가진 정점의 집합
dp[i][0] = 집합 i ~ N번에서 i번 노드가 선택되었을 때 최대 독립 집합 크기
dp[i][1] = 집합 i ~ N번에서 i번 노드가 선택되지 않았을 때 최대 독립 집합 크기
*/

int n, s, e;
int w[MAX], p[MAX];
int dp[MAX][2];
vector<int> v[MAX];
vector<int> ans;

void dfs(int cur) {
    
    dp[cur][0] = w[cur];  // 현재 노드가 선택되었을 경우
    // dp[cur][1] = 0;  // 현재 노드가 선택되지 않았을 경우
    
    for (int nxt : v[cur]) {
        if (p[cur] == nxt) continue;  // 다음이 부모노드라면 (이미 한거니까)
        p[nxt] = cur;  // cur의 자식 : nxt

        dfs(nxt);  // 자식 dfs

        // 현재 노드가 선택되었을 경우
        dp[cur][0] += dp[nxt][1];  // 하위노드는 없어야 함.

        // 현재 노드가 선택되지 않았을 경우
        dp[cur][1] += max(dp[nxt][0], dp[nxt][1]);  // 하위 노드가 선택되던 안되던 상관 X
    }
}

void trace(int cur, bool include){
    // 자신이 포함되어있는 경우 자식은 포함 X
    if (include){
        ans.push_back(cur);
        for (int nxt : v[cur]) {
            if (p[cur] == nxt) continue;  // 부모라면 pass
            trace(nxt, false);
        }
    }
    else {
        for (int nxt : v[cur]) {
            if (p[cur] == nxt) continue;  // 부모라면 pass
            if (dp[nxt][0] > dp[nxt][1]) trace(nxt, true);
            else trace(nxt, false);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> w[i];
    }

    for (int i = 0; i < n - 1; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

    dfs(1);  // 1을 root로 잡고 tree 만들면서 dfs로 dp 생성

    // 1이 포함된 최대값 vs 1이 없는 최대값
    cout << max(dp[1][0], dp[1][1]) << '\n';
    

    // 역추적 (trace)
    if (dp[1][0] > dp[1][1]) trace(1, true);  // 1이 포함된 경우가 최대값
    else trace(1, false);  // 1이 미포함인 경우가 최대값

    sort(ans.begin(), ans.end());

    for(int num : ans){
        cout << num << ' ';
    }
    
    return 0;
}