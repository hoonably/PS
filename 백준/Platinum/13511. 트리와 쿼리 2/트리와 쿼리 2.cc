#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100'001

/*
x의 2^k(2의 k승)번째 조상을 parent[x][k]

getDist 문제에서 dist를 추가로 생성

dist[x][k] = dist[x][k-1] + dist[parent[x][k-1]][k-1]

=> x의 2^(k-1)조상까지의 거리 +  x의 2^(k-1)조상의 2^(k-1)조상까지의 거리
*/

int N, M;
const int TREE_HIGH = 17;  // 최대는 log2(100000) = 16.xx
int MAXK;  // N에 따른 최대 높이
int parent[TREE_HIGH][MAX];  
int depth[MAX];
ll dist[MAX];  // 비용 하나에 100만이니까 long long
vector<pii> v[MAX];

// 트리를 만들면서 각각의 parent, depth, 자신의 부모와의 거리 구하기
void makeTree(int par, int now, int dep, ll cost){

    parent[0][now] = par;   // 부모 노드 기록 [ 2^0 (1)번째 조상 ]
    depth[now] = dep;  // 현재 노드의 깊이 기록
    dist[now] = cost;  // 부모와의 거리 기록

    for(pii child : v[now]){
        // 부모가 아니라면 자식일 수 밖에 없으므로 재귀
        if(child.first != par) makeTree(now, child.first, dep+1, cost + child.second);
    }
}

// 부모 배열과 거리배열 채워줌
void fillParentDist() {  
    for (int k = 1; k <= MAXK; k++)
        for (int i = 1; i <= N; i++)
            parent[k][i] = parent[k-1][parent[k-1][i]];
}

// lca 찾기
int getLca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    int dif = depth[a] - depth[b];

    // a와 b의 높이차를 없애주기 위해
    // a를 높이차 만큼의 부모로 변경
    for(int i=0; dif>0 ; ++i){
        if(dif%2==1) a = parent[i][a];
        dif >>= 1;
    }
 
    if (a == b) return a;

    for (int k = MAXK; k >= 0; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    // 이러면 a와 b의 바로 위의 부모가 같아짐

    return parent[0][a];
}

ll getDist(int u, int v){
    int lca = getLca(u, v);
    // 1->u 거리 + 1->v 거리 - 2*(1->lca 거리)
	return dist[u] + dist[v] - 2*dist[lca];
}

// u에서 v로 가는 경로에 존재하는 정점 중에서 k번째 정점 찾기
int getNodeK(int u, int v, int k){
    int lca = getLca(u, v);

    // u -> lca 거리
	int diff = depth[u] - depth[lca];

    // k번째가 lca라면
    // if(k==diff) return lca;

	k--;

    // u ~ lca 사이라면
	if(k <= diff){
		for(int i=0; k>0; i++){
			if(k%2==1) u = parent[i][u];
			k >>= 1;
		}
		return u;
	}

    // v ~ lca 이라면
	k = depth[v] - depth[lca] + diff - k;
	for(int i=0; k>0; i++){
		if(k%2==1) v = parent[i][v];
		k >>= 1;
	}
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    MAXK = log2(N);

    for (int i=0; i<N-1; i++){
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back({e,cost});
        v[e].push_back({s,cost});
    }

    // 1을 root로 잡고 트리 생성
    makeTree(1, 1, 0, 0);
    fillParentDist();

    cin >> M;
    for (int i=0; i<M; i++){
        int q, u, v, k;
        cin >> q;
        if (q==1){
            // u와 v 사이의 거리
            cin >> u >> v;
            cout << getDist(u, v) << '\n';
        }
        else{
            // u에서 v로 가는 경로에 존재하는 정점 중에서 k번째 정점
            cin >> u >> v >> k;
            cout << getNodeK(u,v,k) << '\n';
        }

    }
    
    return 0;
}