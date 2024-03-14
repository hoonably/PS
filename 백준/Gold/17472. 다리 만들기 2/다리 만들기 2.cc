#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M;
int graph[MAX][MAX];
bool visited[MAX][MAX];
// 땅 번호끼리 최소거리 (2 이상만)
vector<tuple<int, int, int>> v;
int parent[100];

// 땅 번호 매기기
void dfs(int x, int y, int numbering){
    graph[x][y]=numbering;
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
        if (graph[nx][ny]!=1 || visited[nx][ny]==true) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, numbering);
    }
}

// 땅과 땅 사이 거리 구하기
void getDist (int x, int y, int dir){
    int nx = x, ny = y, dist = 0;
    while (true){
        nx += dx[dir];
        ny += dy[dir];
        dist++;
        if ( nx<0 || nx>=N || ny<0 || ny>=M ) return; // 범위 밖은 종료
        if (graph[nx][ny]==graph[x][y]) return;  // 같은 번호의 나라면 종료

        if (graph[nx][ny]!=0) break;  // 다른 나라가 나왔다면 기록준비
    }
    // 거리가 3 이상이면 vector에 dist-1 (다리 길이이므로) 로 간선 기록 
    if (dist >= 3){
        v.push_back({dist-1, graph[x][y], graph[nx][ny]});
    }
}

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> graph[i][j];
        }
    }

    // dfs union
    int numbering = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (graph[i][j]==1 && visited[i][j]==false){
                numbering++;
                visited[i][j]=true;
                dfs(i, j, numbering);
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (graph[i][j]!=0){
                // 4 방향으로 이동
                for (int k=0; k<4; k++){
                    getDist(i, j, k);
                }
            }
        }
    }

    // UNION FIND
    sort(v.begin(), v.end());

    for (int i = 1; i <= numbering; i++) {
        parent[i] = i;
    }

    int ans = 0, cnt = 0;
    for (auto edge : v){
        auto [cost, next, now] = edge;

        // 사이클이라면 PASS
        if (findParent(now) == findParent(next)) continue;

        unionParent(now, next);
        ans += cost;

        // 모든 정점을 연결하는 간선이 V-1개이면 바로 끝
        if (++cnt == numbering-1) {
            cout << ans;
            exit(0);
        }
    }

    // 간선이 V-1개 미만이면 모두 연결이 안되는 것이므로
    cout << -1;

    return 0;
}