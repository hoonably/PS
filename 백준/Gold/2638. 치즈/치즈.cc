#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 101

/*

*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M;
int remain;
int graph[MAX][MAX];
bool visited[MAX][MAX];
set<pii> onePair; // 한번 표면에 닿았던 좌표 임시 저장
vector<pii> deletePair; // 지워질 좌표 저장

// (0,0)에서 
void bfs(){
    queue<pair<int,int>> q;
    q.push({0, 0});
    
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            visited[i][j] = false;
        }
    }
    visited[0][0]=true;
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
            if (visited[nx][ny]) continue;

            // 경로에 치즈가 있다면 (visited 체크 안함)
            if (graph[nx][ny]==1) {

                // 유망한 set에 넣기
                if (onePair.find({nx,ny})==onePair.end()){
                    onePair.insert({nx, ny});
                }
                // 제거하기
                else {
                    onePair.erase({nx,ny});
                    deletePair.push_back({nx,ny});
                    visited[nx][ny]=true;
                    remain--;
                }
                continue;
            }
            visited[nx][ny]=true;
            q.push({nx, ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> graph[i][j];
            if (graph[i][j]) remain++;
        }
    }

    int ans=0;
    while(true){

        onePair.clear();
        deletePair.clear();
        
        bfs();

        // 지우기
        for (pii XY : deletePair){
            graph[XY.first][XY.second] = 0;
        }

        // cout << endl;
        // for(int i=0; i<N; i++){
        //     for (int j=0; j<M; j++){
        //         cout << graph[i][j] << ' ';
        //     } cout << endl;
        // }

        ans++;

        if (remain==0) break;
    }
    cout << ans;
    
    return 0;
}