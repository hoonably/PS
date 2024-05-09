#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/13460

상하좌우로 기울여서
R이 O로 들어가야함.
동시에 R, B 가 들어가면 안됨

#은 장애물, .은 빈공간
*/

#define MAX 10

int N, M;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];  // 빨간 구슬, 파란구슬

// 아래, 위, 오른, 왼
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

tuple<int,int,int,int> go(int dir, int rx, int ry, int bx, int by){

    int nrx=rx, nry=ry, nbx=bx, nby=by;
    // Red
    while(true){
        nrx+=dx[dir]; nry+=dy[dir];
        if (board[nrx][nry]=='#') {
            nrx-=dx[dir]; nry-=dy[dir];
            break;
        }
        // 구멍으로 빠짐 : -1로 표시
        if (board[nrx][nry]=='O'){
            nrx = -1; nry = -1;
            break;
        }
    } 
    // Blue
    while(true){
        nbx+=dx[dir]; nby+=dy[dir];
        if (board[nbx][nby]=='#') {
            nbx-=dx[dir]; nby-=dy[dir];
            break;
        }
        // 구멍으로 빠짐 : -2로 표시
        if (board[nbx][nby]=='O'){
            nbx = -2; nby = -2;
            break;
        }
    }
    // 두 좌표가 같다면 겹칠 수 없으므로 처리
    if(nrx==nbx && nry==nby){
        // 아래로 내려간거라면 위에있던걸 한단계 전으로
        if (dir==0){
            if (bx<rx) nbx -= dx[dir];
            else nrx -= dx[dir];
        }
        // 위로 올라간거라면 아래있던걸 한단계 전으로
        else if (dir==1){
            if (bx>rx) nbx -= dx[dir];
            else nrx -= dx[dir];
        }
        // 오른쪽으로 간거라면 왼쪽에 있던걸 한단계 전으로
        else if (dir==2){
            if (by<ry) nby -= dy[dir];
            else nry -= dy[dir];
        }
        // 왼쪽으로 간거라면 오른쪽에 있던걸 한단계 전으로
        else if (dir==3){
            if (by>ry) nby -= dy[dir];
            else nry -= dy[dir];
        }
    }

    return {nrx, nry, nbx, nby};
}

int bfs(int start_rx, int start_ry, int start_bx, int start_by){
    
    // Red 좌표, Blue좌표, 거리
    queue<tuple<int,int,int,int,int>> q;
    q.push({start_rx, start_ry, start_bx, start_by, 0});
    visited[start_rx][start_ry][start_bx][start_by]=true;
    
    while (!q.empty()){
        auto [rx, ry, bx, by, now_dist] = q.front();

        // 10번 안에 도착 못했을 경우
        // 10도 포함해야하는 이유 : 지금까지 온게 10이면,
        // 다음단계에 도달해도 return은 11이 되기 때문에
        if (now_dist>=10) {
            return -1;
        }

        q.pop();
        for (int i=0; i<4; i++){
            // 이동
            auto [nrx, nry, nbx, nby] = go(i, rx, ry, bx, by);

            // 파란색이 구멍에 빠짐
            if (nbx==-2) continue;

            // 파란색은 안빠지고 빨간색이 구멍에 빠지면 종료
            if (nrx==-1) return now_dist+1;

            if (visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, now_dist + 1});
        }
    }
    return -1;  // 도달 못했을 경우
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    // 시작 지점 찾기
    int rx, ry, bx, by;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (board[i][j]=='R'){
                rx = i; ry = j; break;
            }
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (board[i][j]=='B'){
                bx = i; by = j; break;
            }

    cout << bfs(rx, ry, bx, by);
    
    return 0;
}