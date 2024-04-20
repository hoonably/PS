#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 10001

/*
강한 연결 요소 (SCC)
: 방향 그래프에서 사이클이 발생해 서로가 서로에게 갈 수 있는 것들이 강한 연결 요소다.

SCC를 구하는 타잔 알고리즘(Tarjan's Algorithm)

*/

int id, d[MAX];
bool finished[MAX];
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

    // 부모 노드가 자신인 경우
    if (parent == d[x]){
        vector<int> scc;
        while(true){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t==x) break;
        }
        SCC.push_back(scc);
    }

    return parent;  // 자신의 부모 값을 반환
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int V, E;
    cin >> V >> E;
    for (int i=0; i<E; i++){
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }

    for (int i=1; i<=V; i++){
        if (d[i]==0) dfs(i);
    }

    // 정렬
    for (int i=0; i<SCC.size(); i++){
        sort(SCC[i].begin(), SCC[i].end());  // 내부 정렬
    }
    sort(SCC.begin(), SCC.end());


    cout << SCC.size() << '\n';
    for (auto scc : SCC){
        for (int node : scc){
            cout << node << ' ';
        }
        cout << "-1\n";
    }
    
    return 0;
}