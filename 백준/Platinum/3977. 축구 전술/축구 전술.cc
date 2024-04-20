#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100001

/*
SCC를 구하는 타잔 알고리즘(Tarjan's Algorithm) 이지만,
사이클이 발생하지 않아도 같이 넘어뜨릴 수 있다.

이 문제 조심할 점 -> 0번 노드도 있다.
0번 노드가 있어서 헤맸다.

SCC가 indegree(들어오는 간선)을 가지고 있다면 시작 지점이 될 수 없다.

=> indegree가 0인 SCC가 0개일 수는 없다.

=> indegree가 0인 SCC가 2개면 서로 절대 못가기 때문에 불가능함 -> Confused

=> indegree가 0인 SCC가 1개일 경우 답을 찾아내야함
*/

int id;  // 부모값을 초기화 하는 변수
int d[MAX];  // SCC 부모값을 저장하는 배열
bool finished[MAX];
int SCCID[MAX];  // 각 노드가 몇 번째 SCC에 속하는지
int indegree[MAX];  // 각 SCC의 진입 차수 (여기서 인덱스는 SCC의 번호)
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
            SCCID[t] = SCC.size();  // 그룹 번호 저장 (0번부터)
            finished[t] = true;
            if (t==x) break;
        }
        SCC.push_back(scc);  // 그룹 추가
    }

    return parent;  // 자신의 부모 값을 반환
}

void init(int N){
    id = 0;
    memset(d, -1, sizeof(d));
    memset(finished, false, sizeof(finished));
    memset(SCCID, -1, sizeof(SCCID));
    memset(indegree, 0, sizeof(indegree));
    for (int i=0; i<N; i++) v[i].clear();
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

    for (int i=0; i<N; i++){
        if (d[i]==-1) dfs(i);
    }  // 여기까지 SCC 완료

    
    for (int i=0; i<N; i++){
        for (int nxt : v[i]){  // i번 도미노에 연결된 도미노들 중 
            // 서로 다른 그룹이라면 그 그룹의 진입차수 증가시킴
            // 왜냐면 i를 무너뜨리면 w가 속해있는 그룹도 무너지는것이므로
            if (SCCID[nxt]!=SCCID[i]){ 
                indegree[SCCID[nxt]]++;  
            }
        }
    }

    // for (auto scc : SCC){
    //     for (int node : scc){
    //         cout << node << ' ';
    //     }
    //     cout << "\n";
    // }
    // return;

    int notInIdx = -1;  // 진입 불가능한 그룹의 번호
    for (int i=0; i<SCC.size(); i++){
        if (indegree[i]==0) {
            if (notInIdx==-1) {
                notInIdx = i;
            }
            else {  // indegree가 0인 SCC가 두개 이상이라면 절대 불가능
                cout << "Confused\n";
                return;
            }
        }
    }

    for(int i = 0; i < N; i++){
        // i가 진입하지 않는 그룹의 사이클이라면
        if(SCCID[i] == notInIdx){  
            cout << i << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
    
    return 0;
}