#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int V, E;
int color[20001];
vector<vector<int>> graph(20001);

bool bfs(int start_node) {
    queue<pair<int, int>> q;
	q.push({ start_node, 1 });
	color[start_node] = 1;
	
	while(!q.empty()){ 
        auto [cur_node, cur_color] = q.front();
		q.pop();

		for (int next_node : graph[cur_node]) {
            // 비트연산 이용해서 0이면 1, 1이면 0 반환
			int next_color = cur_color ^ 1;

            // color가 색칠되어있다면
			if (color[next_node] > -1) {
				if (next_color != color[next_node]) return false;  // 다른걸로 색칠되어있다면
			}
            // color가 색칠되어있지 않다면
            else{
                color[next_node] = next_color;
			    q.push({ next_node, next_color });
            }
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {

		cin >> V >> E;

        // 기존의 배열 초기화
		for (int i = 1; i <= V; i++) {
			graph[i].clear();
			color[i] = -1;
		}

		for (int i = 0; i < E; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		int flag = true;

		for (int i = 1; i <= V; i++) {
			if (color[i] == -1) {  // bfs 안돌았다면 실행
				flag = bfs(i);
				if(!flag) break;
			}
		}
		
		if(flag) cout << "YES\n";
		else cout << "NO\n";
			
	}

}