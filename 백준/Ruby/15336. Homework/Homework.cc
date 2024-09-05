#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/15336
3개로 분할해서 400*3 개의 vertex
*/

const int vertexSZ = 1200;  // in out 분할이라면 2배
const int SZ = vertexSZ+10, bias = vertexSZ/2;
int SRC = vertexSZ+1, SINK = vertexSZ+2;

struct NetworkFlow{  // use Dinic

    using FlowType = int;

    struct Edge{ int to, rev; FlowType cap; };
    vector<Edge> graph[SZ];
    int level[SZ], work[SZ];

    // 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
    void addEdge(int _from, int _to, FlowType _cap, FlowType _caprev = 0){
        graph[_from].push_back({_to, (int)graph[_to].size(), _cap});
        graph[_to].push_back({_from, (int)graph[_from].size()-1, _caprev});
    }

    void initGraph(){ // for Test Case
        for (int i=0; i<SZ; i++) graph[i].clear();
    }

    bool BFS(int S, int T){  // make level graph
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(S); level[S] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(const auto &next : graph[now]){
                if(!level[next.to] && next.cap) q.push(next.to), level[next.to] = level[now] + 1;
            }
        }
        return level[T];
    }
    FlowType DFS(int now, int T, FlowType flow){  // find Blocking Flow
        if(now == T) return flow;
        for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &next = graph[now][work[now]];
            if(level[next.to] != level[now] + 1 || !next.cap) continue;
            FlowType ret = DFS(next.to, T, min(flow, next.cap));
            if(!ret) continue;
            next.cap -= ret;
            graph[next.to][next.rev].cap += ret;
            return ret;
        }
        return 0;
    }
    FlowType maxFlow(int S = SRC, int T = SINK){
        FlowType ret = 0, minFlow;
        while(BFS(S, T)){
            memset(work, 0, sizeof(work));
            while((minFlow = DFS(S, T, INF))) ret += minFlow;
        }
        return ret;
    }
} nf;

pii edges[vertexSZ];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=M; i++){
        cin >> edges[i].first >> edges[i].second;
        nf.addEdge(SRC,i,1);
        for(int j=edges[i].first;j<=edges[i].second;j++){
            nf.addEdge(i,j+400,1);
        }
    }

    for(int i=1; i<=400; i++){
        nf.addEdge(i+400,i+800,1);
    }

    for(int i=M+1; i<=N; i++){
        cin >> edges[i].first >> edges[i].second;
        nf.addEdge(i,SINK,1);
        for(int j=edges[i].first;j<=edges[i].second;j++){
            nf.addEdge(j+800,i,1);
        }
    }

    // 그리디 알고리즘
    priority_queue<int, vector<int>, greater<int>> Q;  // 최소 힙
    sort(edges+1,edges+N+1);
    int now=1, cnt=0;
    for(int i=1; i<=400; i++){

        // Edge의 시작점이 i인것 모두 도착점을 Q에 넣기
        while(now<=N && i==edges[now].first) Q.push(edges[now++].second);

        // i보다 큐의 최소값보다 크다면 pop하고 정답 올리기
        if(!Q.empty() && i<=Q.top()) {Q.pop(); cnt++;}

        // i보다 작거나 같은거 모두 빼기
        while(!Q.empty() && i>=Q.top()){Q.pop();}
    }
    cout << cnt << '\n';
    cout << nf.maxFlow();

    return 0;
}