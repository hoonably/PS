#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/17412
네트워크 플로우

*/

#define MAX 401

int N, P;
int flow[MAX][MAX];
int cap[MAX][MAX];
vector<vector<int>> grid(MAX);

int edmonds_karp(int start, int end) {
    int ret = 0;
    while (true) {
        queue<int> q;
        q.push(start);  // 출발
        vector<int> parent(N + 1, -1);
        int minflow = INF;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : grid[cur]) {
                if (cap[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                    if (next == end) break;
                }
            }
        }

        // 도착지점
        if (parent[end] == -1) break;  // 도달 실패

        // 거꾸로 최소 유량 찾기
        for (int i = end; i != start; i = parent[i]) {
            minflow = min(minflow, cap[parent[i]][i] - flow[parent[i]][i]);
        }

        // 최소 유량만큼 추가
        for (int i = end; i != start; i = parent[i]) {
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
        }
        ret += minflow;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> P;
    for(int i=0; i<P; i++){
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
        cap[a][b] = 1;
    }

    cout << edmonds_karp(1, 2);
    
    return 0;
}