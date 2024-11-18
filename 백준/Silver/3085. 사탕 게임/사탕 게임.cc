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

int N;
char board[50][50];
int ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void cnt(){
    for(int i=0; i<N; i++){
        int row = 1, col = 1;
        for(int j=1; j<N; j++){
            if(board[i][j] == board[i][j-1]) row++;
            else{
                ans = max(ans, row);
                row = 1;
            }
            if(board[j][i] == board[j-1][i]) col++;
            else{
                ans = max(ans, col);
                col = 1;
            }
        }
        ans = max({ans, row, col});
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> board[i][j];
    
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[i][j] == board[nx][ny]) continue;

            swap(board[i][j], board[nx][ny]);
            cnt();
            // backtracking
            swap(board[i][j], board[nx][ny]);
        }
    }
    cout << ans;
    
    return 0;
}