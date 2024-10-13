#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

int N, M;
char board[1001][1001];
int sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    // 홀수개면 불가능
    if (N%2 && M%2) {
        cout << "-1";
        return 0;
    }

    int a;
    memset(board, -1, sizeof(board));
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
        cin >> a;
        sum += a;
        board[i][j] = a;
    }

    // 1의 개수가 홀수인가?
    if (sum % 2) {
        cout << "-1";
        return 0;
    }

    // 처음에 한번이라도 없어지면 가능
    // 자신의 오른쪽과 아래에 있는 것을 비교
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (board[i][j] == board[i+1][j]) {
                cout << "1";
                return 0;
            }
            if (board[i][j] == board[i][j+1]) {
                cout << "1";
                return 0;
            }
        }
    }

    // 못지우면 불가능
    cout << "-1";
    
    return 0;
}