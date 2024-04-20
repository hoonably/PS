#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100001

/*
SCC를 구하는 타잔 알고리즘(Tarjan's Algorithm) 이지만,
사이클이 발생하지 않아도 같이 넘어뜨릴 수 있다.
=> indegree가 0인 SCC의 개수가 답
*/

int id, d[MAX];
bool finished[MAX];
int group[MAX];  // 각 도미도(노드)가 몇 번째 SCC에 속하는지 그룹으로 기록하는 배열
int indegree[MAX];  // 각 SCC를 하나의 정점으로 간주하고 정점의 진입 차수를 기록하는 배열
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;

// DFS는 총 정점의 갯수만큼 식행 된다.
int dfs(int x){
    d[x] = ++id;  // 노드마다 고유 번호 할당
    s.push(x);

    int parent = d[x];  // 자신이 부모
    for (int child : v[x]){
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
            group[t] = SCC.size() + 1;
            finished[t] = true;
            if (t==x) break;
        }
        SCC.push_back(scc);
    }

    return parent;  // 자신의 부모 값을 반환
}

void solve(){
    int N, M;
    cin >> N >> M;

    // 초기화
    id = 0;
    SCC.clear();
    for (int i=0; i<=N; i++){
        d[i] = 0;
        finished[i] = false;
        v[i].clear();
        indegree[i]=0;
        group[i]=0;
    }

    for (int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }

    for (int i=1; i<=N; i++){
        if (d[i]==0) dfs(i);
    }

    for (int i=1; i<=N; i++){
        for (int w : v[i]){
            if (group[w]==group[i]) continue;
            indegree[group[w]]++;
        }
    }
    
    int ans = 0;
    for (int i=0; i<SCC.size(); i++){
        if (indegree[i]==0) ans++;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}