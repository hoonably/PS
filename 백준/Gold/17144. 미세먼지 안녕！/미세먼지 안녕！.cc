#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX


/*

*/

int R, C, T;
int graph[50][50];
int temp[50][50];
int air;  // 공기청정기 윗부분의 위치 (1열의 무슨 행인지)
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

// temp로 그래프 복사
void copyGraph(){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            temp[i][j] = graph[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C >> T;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin >> graph[i][j];
        }
    }

    // 공기청정기 위치 기록
    for (int i=0; i<R; i++){
        if (graph[i][0]==-1) {
            air = i;
            break;
        }
    }

    while(T--){
        // temp에 복사
        copyGraph();

        // 미세먼지 확산
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){

                // 5보다 작으면 확산안됨 (-1 포함)
                if (temp[i][j]<5) continue;

                for (int d=0; d<4; d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni<0 || ni>=R || nj<0 || nj>=C) continue;
                    if (temp[ni][nj]==-1) continue;

                    graph[ni][nj] += temp[i][j] / 5;
                    graph[i][j] -= temp[i][j] / 5;
                }
            }
        }

        // 공기청정기 가동
        // 거꾸로 먹어가는 듯이 가동

        // 위쪽
        for (int i=air-1; i>=1; i--){
            graph[i][0] = graph[i-1][0];
        }
        for (int j=0; j<C-1; j++){
            graph[0][j] = graph[0][j+1];
        }
        for (int i=0; i<air; i++){
            graph[i][C-1] = graph[i+1][C-1];
        }
        for (int j=C-1; j>1; j--){
            graph[air][j] = graph[air][j-1];
        }
        graph[air][1] = 0;  // 깨끗한 공기

        // 아래쪽
        for (int i=air+2; i<R-1; i++){
            graph[i][0] = graph[i+1][0];
        }
        for (int j=0; j<C-1; j++){
            graph[R-1][j] = graph[R-1][j+1];
        }
        for (int i=R-1; i>air+1; i--){
            graph[i][C-1] = graph[i-1][C-1];
        }
        for (int j=C-1; j>1; j--){
            graph[air+1][j] = graph[air+1][j-1];
        }
        graph[air+1][1] = 0;  // 깨끗한 공기

        // cout << endl;
        // for (int i=0; i<R; i++){
        //     for (int j=0; j<C; j++){
        //         cout <<  graph[i][j] << ' ';
        //     } cout << endl;
        // }
    }

    int ans = 2;  // 공기청정기 두개 반영
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            ans += graph[i][j];
        }
    }

    cout << ans;
    
    return 0;
}