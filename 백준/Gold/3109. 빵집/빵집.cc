#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
가장 왼쪽 열(C)에서 가장 오른쪽 열(C)로
최대한 많은 파이프를 놓는 경우의 수

시간초과 이유
그리디로 위부터 탐색하기 때문에 굳이 다시 백트래킹을 해줄 필요가 없다.
만약 지났던 곳으로 갔을 경우 통과를 못한다면 결국 다시 가도 통과를 못한다.
*/

int R, C;
int ans;
char graph[10001][501];
int dy[] = {-1,0, 1};

bool backtracking(int row, int level){
    graph[row][level] = 'x';

    if(level==C-1){
        return true;
    }
    
    for (int i=0; i<3; i++){
        int nr = row + dy[i];
        if (nr<0 || nr>=R || graph[nr][level+1]=='x') continue;
        if (backtracking(nr, level+1)) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin >> graph[i][j];
        }
    }

    for (int i=0; i<R; i++){
        if (backtracking(i, 0)) ans++;
    }
    cout << ans;

    return 0;
}