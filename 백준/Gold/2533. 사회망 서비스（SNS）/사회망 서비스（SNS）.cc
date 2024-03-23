#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1000001

/*
얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 
얼리 아답터일 때만 이 아이디어를 받아들인다. 

얼리 어답터의 최소 수를 구하시오

dp[i][0] = 집합 i ~ N번에서 i번이 얼리어답터일 때 최소값
dp[i][1] = 집합 i ~ N번에서 i번이 얼리어답터가 아닐 때 최소값
*/

int N;
vector<int> v[MAX];
bool visited[MAX];
int dp[MAX][2];

void dfs(int now){
    
    visited[now] = true;

    dp[now][0]=1;  // 본인이 얼리어답터인 경우

    for(int nxt : v[now]){
        if(visited[nxt]) continue;  // 부모노드인 경우 PASS
        dfs(nxt);

        // 현재 얼리어답터 X : 자식은 모두 얼리어답터
        dp[now][1] += dp[nxt][0];
        
        // 현재 얼리어답터 : 자식은 얼리어답터 or 얼리어답터 X (둘 중 최소값 갱신)
        dp[now][0] += min(dp[nxt][1], dp[nxt][0]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
        int s, e;
		cin >> s >> e;
        v[s].push_back(e);
		v[e].push_back(s);
	}

    dfs(1);
	cout << min(dp[1][0], dp[1][1]);

	return 0;
}