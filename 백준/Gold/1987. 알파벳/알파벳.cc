#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int R, C, ans=0;
char board[20][20];
bool alphabet[26];

void dfs(int x, int y, int cnt){
    ans = max(ans, cnt);
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ( nx<0 || nx>=R || ny<0 || ny>=C ) continue;
        if (alphabet[board[nx][ny]-'A']) continue;

        alphabet[board[nx][ny]-'A'] = true;
        dfs(nx, ny, cnt+1);
        alphabet[board[nx][ny]-'A'] = false;  // backtracking
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C;

    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin >> board[i][j];
        }
    }

    // 시작점
    alphabet[board[0][0]-'A'] = true;

    dfs(0,0,1);
    cout << ans;
    
    return 0;
}