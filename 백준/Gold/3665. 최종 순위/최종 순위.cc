#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
작년에 팀 13이 팀 6 보다 순위가 높았는데, 올해 팀 6이 팀 13보다 순위가 높다면, (6, 13)을 발표

단 하나의 경우의 수만 등장하는지 확인 ->  하나의 노드에서 여러 노드로 퍼질 수 있다면 "?" 출력

사이클이 존재하다면 IMPOSSIBLE을 출력
*/

int T, N, M, num[501], x, y;
int inDegree[501];  // 앞에 와야 하는 팀 개수
bool adj[501][501];  // adj[a][b] = true : a팀 다음에 b팀  

void topologySort() {

	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	vector <int> res;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		res.push_back(now);
		inDegree[now]--;

		for (int i = 1; i <= N; i++) {
			if (adj[now][i]) inDegree[i]--;
			if (inDegree[i] == 0) q.push(i);
		}
	}
    // 성공
	if (res.size() == N) {
		for (int i = 0; i < N; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
    // 사이클 존재
	else cout << "IMPOSSIBLE\n";
}

void init(){
    memset(inDegree, 0, sizeof(inDegree));
    memset(adj, 0, sizeof(adj));
}

void solve(){

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    // 이전년도 adj, inDegree 값 정하기
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            adj[num[i]][num[j]] = true; // num[i] 다음에 num[j]
            inDegree[num[j]]++;
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        if (adj[x][y]) { // 원래 x가 y 앞이었던 경우
            adj[x][y] = false;
            adj[y][x] = true;
            inDegree[y]--;
            inDegree[x]++;  // x 앞에 y가 생김
        }
        else { // 원래 y가 x 앞이었던 경우
            adj[y][x] = false;
            adj[x][y] = true;
            inDegree[x]--;
            inDegree[y]++;
        }
    }
    topologySort();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
	while (T--) {
        init();
		solve();
	}

    return 0;
}