#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 500001

/*
SCC를 구하는 타잔 알고리즘(Tarjan's Algorithm) 이지만,

SCC안에 있는 ATM은 어차피 사이클을 돌면서 무조건 다 인출할것이다.

SCC를 하나의 노드라고 생각하면
사이클이 없기 때문에 위상정렬이 가능하다.
위상정렬을 하면서 dp를 갱신하면 된다.
*/

// 인수가 idx
int id;  // 부모값을 초기화 하는 변수
int d[MAX];  // SCC 부모값을 저장하는 배열
bool finished[MAX];
int sccID[MAX];
vector<int> graph[MAX];

// 인수가 SCC
int sccSize;
int sccMoney[MAX];  // SCC에 ATM에 돈이 얼마나 있는지 합
bool sccRest[MAX];  // 레스토랑이 있는 SCC인지
int sccIndegree[MAX];  // 진입차수
int sccDp[MAX];
vector<int> sccGraph[MAX];
vector<vector<int>> SCC;
stack<int> s;


int S, P;

// DFS는 총 정점의 갯수만큼 식행 된다.
int dfs(int x){
    d[x] = ++id;  // 노드마다 고유 번호 할당
    s.push(x);

    int parent = d[x];  // 자신이 부모
    for (int child : graph[x]){
        // 방문 안한 노드
        if (d[child] == 0) parent = min(parent, dfs(child));
        // 방문은 했지만 처리가 안된 노드
        else if (!finished[child]) parent = min(parent, d[child]);
    }

    // 부모 노드가 자신인 경우 (사이클인 경우)
    if (parent == d[x]){
        vector<int> scc;
        while(true){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            sccID[t] = SCC.size();  // 그룹 번호 저장
            finished[t] = true;
            if (t==x) break;
        }
        SCC.push_back(scc);
    }

    return parent;  // 자신의 부모 값을 반환
}

void topology_sort() {
	queue<int> q;

	for (int i = 0; i < sccSize; i++) {
		if (sccIndegree[i] == 0)
			q.push(i); // 진입차수가 0인 노드 push
	}

    // 시작 SCC는 무조건 돈 뽑음
    sccDp[sccID[S]] = sccMoney[sccID[S]];
    bool flag = false;  // 시작점 나온 이후부터는 true로 바뀌어 sccDp 갱신

	for (int rep = 0; rep < sccSize; rep++) {
		int now = q.front();
		// cout << now << ' ';
		q.pop();

        if (now==sccID[S]) flag = true;  // 시작지점 도달

		for (int next : sccGraph[now]) {
            if (flag){
                sccDp[next] = max(sccDp[next], sccDp[now]+sccMoney[next]);
            }
			sccIndegree[next]--;
			if (sccIndegree[next] == 0)
				q.push(next);
		}
	}
}


void solve(){
    int N, M;
    cin >> N >> M;

    for (int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }

    // SCC 생성
    for (int i=1; i<=N; i++){
        if (d[i]==0) dfs(i);
    }
    sccSize = SCC.size();

    // SCC 그래프 생성 + 진입차수 갱신
    for (int cur = 1; cur <= N; ++cur) 
		for (int next : graph[cur]) 
			if (sccID[cur] != sccID[next]) {
				sccGraph[sccID[cur]].push_back(sccID[next]);
				sccIndegree[sccID[next]]++;
			}

    // ATM에 있는 돈 SCC별로 묶어서 정리
    for (int i=1; i<=N; i++){
        int m;
        cin >> m;
        sccMoney[sccID[i]]+=m;
    }

    // 시작지점과 레스토랑 위치 받기
    cin >> S >> P;
    for (int i=0; i<P; i++){  // 레스토랑이 있는 SCC 체크
        int r;
        cin >> r;
        sccRest[sccID[r]] = true;
    }

    topology_sort();// 위상정렬 하면서 sccDp 갱신

    int ans = 0;
    for (int i=0; i<sccSize; i++){  // 레스토랑이 있는 SCC 중 최대값 구하기
        if (sccRest[i]){
            ans = max(ans, sccDp[i]);
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    solve();
    
    return 0;
}