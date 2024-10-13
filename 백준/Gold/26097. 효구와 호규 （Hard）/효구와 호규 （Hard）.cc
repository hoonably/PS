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
char board[1002][1002];
int sum;

void print(){
    // 0 두개 지우기
    bool flag = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if (board[i][j] == '0') {
                board[i][j] = '2';
                cout << i << ' ' << j << ' ';
                flag ^= 1;
                if (flag) cout << '\n';  // 두개의 0을 지웠을 때만 줄바꿈
            }
        }
    }
    // 1 두개 지우기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if (board[i][j] == '1') {
                board[i][j] = '2';
                cout << i << ' ' << j << ' ';
                flag ^= 1;
                if (flag) cout << '\n';  // 두개의 1을 지웠을 때만 줄바꿈
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    // 총 홀수개면 불가능
    if (N%2 && M%2) {
        cout << "-1";
        return 0;
    }

    memset(board, 'x', sizeof(board));
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
        cin >> board[i][j];
        sum += (board[i][j] == '1');
    }

    // 1과 0의 개수가 홀수인가?
    if (sum % 2) {
        cout << "-1";
        return 0;
    }

    // 처음에 한번이라도 없어지면 가능
    // 자신의 오른쪽과 아래에 있는 것을 비교
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
        if (board[i][j] == board[i+1][j]) {
            cout << "1\n";
            board[i][j] = board[i+1][j] = '2';
            cout << i << ' ' << j << ' ' << i+1 << ' ' << j << '\n';
            print();
            return 0;
        }
        if (board[i][j] == board[i][j+1]) {
            cout << "1\n";
            board[i][j] = board[i][j+1] = '2';
            cout << i << ' ' << j << ' ' << i << ' ' << j+1 << '\n';
            print();
            return 0;
        }
    }

    // 못지우면 불가능
    cout << "-1";
    
    return 0;
}