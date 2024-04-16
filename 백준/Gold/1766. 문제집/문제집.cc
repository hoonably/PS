#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

우선순위 큐를 사용한 위상정렬
*/

int N, M;
int inDgree[32001];  // 진입차수 (자신으로 오는 노드의 개수)
vector<int> graph[32001];

void topology_sort() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++) {
		if (inDgree[i] == 0)
			pq.push(i); // 진입차수가 0인 노드 push
	}

	for (int rep = 0; rep < N; rep++) {
		if (pq.empty()) {
			cout << "비순환 그래프입니다" << endl;
			return;
		}

		int now = pq.top();
		cout << now << ' ';
		pq.pop();

		for (int next : graph[now]) {
			inDgree[next]--;
			if (inDgree[next] == 0)
				pq.push(next);
		}
	}

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDgree[b]++;  // 진입차수
    }

    topology_sort();

    return 0;
}