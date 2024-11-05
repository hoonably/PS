#include <bits/stdc++.h>
using namespace std;

// 강한 연결 요소 (SCC) Strongly Connected Component
// 타잔 알고리즘(Tarjan's Algorithm) 
// O(V+E)
const int MAXN = 101;
struct SCC{
    int sccSize;
    int id;  // 부모값을 초기화 하는 변수
    int d[MAXN];  // SCC 부모값 저장
    bool finished[MAXN];
    int SCCID[MAXN];  // 각 노드가 몇 번째 SCC에 속하는지 그룹으로 기록하는 배열
    vector<int> graph[MAXN];
    vector<vector<int>> SCC;
    stack<int> stk;

    int dfs(int x){
        d[x] = ++id;  // 노드마다 고유 번호 할당
        stk.push(x);

        int parent = d[x];  // 자신이 부모
        for (int child : graph[x]){
            // 방문 안한 노드
            if (d[child] == -1) parent = min(parent, dfs(child));
            // 방문은 했지만 처리가 안된 노드
            else if (!finished[child]) parent = min(parent, d[child]);
        }

        // 부모 노드가 자신인 경우 (사이클인 경우)
        if (parent == d[x]){
            vector<int> scc;
            while(true){
                int t = stk.top();
                stk.pop();
                scc.push_back(t);
                finished[t] = true;
                if (t==x) break;
            }
            SCC.push_back(scc);
        }
        return parent;  // 자신의 부모 값을 반환
    }
    void get_scc(int N) {  // 1~N 범위 SCC 구하기
        for (int i = 1; i <= N; ++i)
            if (d[i]==-1) dfs(i);
    }

    int indegree[MAXN];  // 각 'SCC의' 진입 차수 (인덱스: SCC 번호)
    void make_indegree(int N){  // 1~N 범위 SCC의 진입차수 구하기
        for (int i=1; i<=N; i++)
            for (int nxt : graph[i])
                if (SCCID[nxt]!=SCCID[i])
                    indegree[SCCID[nxt]]++;  
    }  // 그 후 진입차수가 0인 SCC를 이용해서 문제를 풀면 됨.

    void init(int N){
        memset(d, -1, sizeof(d));
        /* for test case
        id = 0;
        sccSize = 0;
        memset(finished, false, sizeof(finished));
        memset(indegree, 0, sizeof(indegree));
        for (int i=1; i<=N; i++) graph[i].clear();
        */
    }
}scc;

int costs[MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    scc.init(N);
    for(int i=1; i<=N; i++) cin >> costs[i];

    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++){
        char c; cin >> c;
        if (c=='1') scc.graph[i].push_back(j);
    }
    scc.get_scc(N);

    int cost = 0;
    for(auto s : scc.SCC){
        int min_cost = INT_MAX;
        for(int i : s) min_cost = min(min_cost, costs[i]);
        cost += min_cost;
    }
    cout << cost;

    return 0;
}