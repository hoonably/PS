#include<iostream>
#include<vector>
#include<queue>

using namespace std;
constexpr int INF = 0x7f7f7f7f;
int N, M, K;
vector<int> A, dist, parent;
vector<vector<pair<int,int>>> adj;

int getFirstCon(int num)
{
	if (A[num]) return num;
	return parent[num] = getFirstCon(parent[num]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	A.resize(N + 1);
	adj.resize(N + 1);
	dist.resize(N + 1, INF);
	parent.resize(N + 1, -1);
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 0; i < M; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	priority_queue<pair<int, int>> pq; //<-cost, node>
	dist[1] = 0;
	parent[1] = 0;
	pq.emplace(0, 1);
	while (!pq.empty())
	{
		int curCost = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (dist[curNode] < curCost) continue;
		for (auto& next : adj[curNode])
		{
			int nextCost = curCost + next.second;
			if (nextCost < dist[next.first])
			{
				dist[next.first] = nextCost;
				parent[next.first] = curNode;
				pq.emplace(-nextCost, next.first);
			}
			else if (nextCost == dist[next.first] && parent[next.first] < curNode)
			{
				parent[next.first] = curNode;
			}
		}
	}

	A[0] = 1;
	for (int i = 0; i < K; ++i)
	{
		int s, sel = -1;
		cin >> s;
		if (parent[s] != -1)
		{
			sel = getFirstCon(s);
			if (sel == 0) //경로상의 편의점들 모두 재고 없음
				sel = -1;
			else
				--A[sel];
		}
		cout << sel << '\n';
	}
}