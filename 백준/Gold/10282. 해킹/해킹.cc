#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

int n, d, c;
vector<vector<pii>> graph;

int dijkstra(int start){
    vector<int> dist(n+1, INF);
    priority_queue<pii> pq;
    
    dist[start] = 0;
    pq.push({0, start});  // {dist, node}
    
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 테이블보다 가중치가 큰 튜플이면 무시
        if (cur_dist > dist[cur_node]) continue;

        for (auto& edge : graph[cur_node]) {
            int nxt_node = edge.first;
            int nxt_dist = edge.second + cur_dist;
            
            if (nxt_dist < dist[nxt_node]) {  // 유망하면
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
    
    int cnt = 0, max_time = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] != INF){
            cnt++;
            max_time = max(max_time, dist[i]);
        }
    }
    cout << cnt << ' ' << max_time << '\n';
    return 0;
}

void solve(){
    graph.clear();
    cin >> n >> d >> c;
    graph.resize(n+1);
    while(d--){
        int a, b, s;
        cin >> a >> b >> s;
        graph[b].push_back({a, s});  // 컴퓨터 b가 감염되면 s초 후부터 a가 감염됨
    }
    dijkstra(c);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}