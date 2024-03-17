#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 8

/*

*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M;
int graph[MAX][MAX];
int tmp[MAX][MAX];
bool visited[MAX*MAX];
vector<pii> space;  // 빈 공간
int ans = 0;

void copy(int tmp[MAX][MAX], int graph[MAX][MAX]) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			tmp[i][j] = graph[i][j];
		}
	}
}

void bfs() {
	
	queue<pair<int, int>> q;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(tmp[i][j]==2) {
				q.push({i, j});
			}
		}
	}
	
	while(q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx = x+dx[k];
			int ny = y+dy[k];
			
			if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
			if(tmp[nx][ny]==0) {
				tmp[nx][ny] = 2;
				q.push({nx, ny});
			}
		}
	}
	
	int cnt=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(tmp[i][j]==0) {
				cnt++;
			} 
		}
	}
	ans = max(ans, cnt);
}

// 3개를 막았다면 bfs
void wall(int cur, int idx) {

	if(cur==3) {
		copy(tmp, graph);
		int cnt=0;
		for(int i=0; i<space.size(); i++) {
			if(cnt==3) break;
			if(visited[i]) {
				int x = space[i].first;
				int y = space[i].second;
				tmp[x][y] = 1;
				cnt++;
			}
		}
		bfs();
		return;
	}
	
	for(int i=idx; i<space.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		wall(cur+1, i);
		visited[i] = false;
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> graph[i][j];
            if (graph[i][j]==0) space.push_back({i,j});
        }
    }

    wall(0, 0);
	cout << ans;
    
    return 0;
}