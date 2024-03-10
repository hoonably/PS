#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*
바로 이전에 방문한 노드는 양방향이지만 영향을 받지 않아야 하기 때문에 
따로 예외처리
*/

bool visited[501];

bool dfs(int now_node, int before, const vector<int> graph[]){

    visited[now_node] = true;

    for (int nxt_node : graph[now_node]){
        if (nxt_node==before) continue;  // 바로 이전에 방문한 곳인 경우 PASS

        if (visited[nxt_node]) return false;

        // 다음 노드에서 함수가 tree가 아니면 지금 노드도 트리가 아님
        if (dfs(nxt_node, now_node, graph)==false) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    while(true){
        int n, m;
        cin >> n >> m;
        if (n==0) break;

        vector<int> graph[n+1];
        for (int i=0; i<m; i++){
            int s, e;
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
        // 초기화

        fill(visited, visited+n+1, false);

        int cnt = 0;
        for (int i = 1; i <= n; i++){
			if (!visited[i]){
                if (dfs(i, 0, graph)) cnt++;
            }
		}

        if (cnt == 0) printf("Case %d: No trees.\n", T);
        else if (cnt == 1) printf("Case %d: There is one tree.\n", T);
        else printf("Case %d: A forest of %d trees.\n", T, cnt);

        T++;
    }
    
    return 0;
}