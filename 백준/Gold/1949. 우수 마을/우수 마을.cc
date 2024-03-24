#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 10001


/*
우수마을끼리는 인접 X
우수마을이 아닌 마을은 적어도 하나의 우수마을과는 인접해야함.

우수마을 주민 수들의 합의 최대치 구하기
dp[i][0] = i번이 우수마을 일 때 최대값
dp[i][1] = i번이 우수마을 아님
*/

int N, s, e;
vector<int> v[MAX];
bool visited[MAX];
int w[MAX];
int dp[MAX][2];

void dfs(int now){
    
    visited[now] = true;

    dp[now][0] = w[now];  // 본인이 우수 마을인 경우

    for(int nxt : v[now]){
        if(visited[nxt]) continue;  // 부모노드인 경우 PASS
        dfs(nxt);

        // 현재 우수마을 : 자식은 우수마을 X
        dp[now][0] += dp[nxt][1];

        // 현재 우수 마을 X : 자식은 우수마을 or 우수마을 X
        // 하지만 모두 우수마을이 아니면 안됨
        dp[now][1] += max(dp[nxt][0], dp[nxt][1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> w[i];
    }

    for (int i = 0; i < N - 1; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    
    return 0;
}