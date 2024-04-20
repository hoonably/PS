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

int id;  // 부모값을 초기화 하는 변수
int d[MAX];  // SCC 부모값을 저장하는 배열
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
        if (d[child] == -1) parent = min(parent, dfs(child));
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
            group[t] = SCC.size() + 1;  // 그룹 번호 저장
            finished[t] = true;
            if (t==x) break;
        }
        SCC.push_back(scc);
    }

    return parent;  // 자신의 부모 값을 반환
}

void init(int N){
    id = 0;
    memset(d, -1, sizeof(int)*(N+1));
    memset(finished, false, sizeof(bool)*(N+1));
    memset(indegree, 0, sizeof(int)*(N+1));
    for (int i=1; i<=N; i++) v[i].clear();
    SCC.clear();
}

void solve(){
    int N, M;
    cin >> N >> M;

    init(N);

    for (int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }

    for (int i=1; i<=N; i++){
        if (d[i]==-1) dfs(i);
    }  // 여기까지 SCC 완료

    
    for (int i=1; i<=N; i++){
        for (int w : v[i]){  // i번 도미노에 연결된 도미노들 중 
            // 서로 다른 그룹이라면 그 그룹의 진입차수 증가시킴
            // 왜냐면 i를 무너뜨리면 w가 속해있는 그룹도 무너지는것이므로
            if (group[w]!=group[i]){ 
                indegree[group[w]]++;  
            }
        }
    }
    
    // 이제 indegree(진입차수)가 0인 곳의 개수를 출력
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