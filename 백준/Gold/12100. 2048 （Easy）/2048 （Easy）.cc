#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int N;
int graph[21][21];
int ans;

// 4방향을 모두 구현하기엔 함수가 4개가 필요하기 때문에
// 90도로 회전시키는 함수 이용
void rotation(int arr[][21]) {
    int temp[21][21];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[j][N - 1 - i] = arr[i][j];

    // temp를 arr에 복사
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = temp[i][j];
}

// 아래로 움직이기
void moveDown(int arr[][21]){
    for (int i=0; i<N; i++){
        deque<int> dq;
        // 이미 합쳐진건 또 합치면 안됨
        // ex) 1 1 2  -> 2 2 로 남아있어야 함
        bool alreadyMerge = false;

        for (int j=0; j<N; j++){
            if (arr[i][j]==0) continue;

            // 그 전에 같은 숫자가 나오고, 이미 합쳐진게 아니라면
            if (!dq.empty() && arr[i][j] == dq.back() && !alreadyMerge){
                dq.pop_back();
                dq.push_back(arr[i][j]*2);
                alreadyMerge = true;
            }
            // 덱에 넣기
            else {
                dq.push_back(arr[i][j]);
                alreadyMerge = false;
            }
        }

        for (int j=0; j<N; j++){
            if (!dq.empty()){
                arr[i][j] = dq.front();
                dq.pop_front();
            }
            else arr[i][j] = 0;
        }
    }
}

void backtracking(int level){
    if (level==5) {
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                ans = max(ans, graph[i][j]);
            }
        }
        return;
    }

    int temp[21][21];

    for(int i = 0; i < 4; i++) {
        memcpy(temp, graph, sizeof(graph)); // origin -> copy
        moveDown(graph);

        backtracking(level + 1);

        memcpy(graph, temp, sizeof(graph)); // copy -> origin
        rotation(graph);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> graph[i][j];
        }
    }

    backtracking(0);

    cout << ans;
    
    return 0;
}