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

int N, M;
char A[50][50];
int ans = 0;

void brute(int x, int y){
    int i = 1;
    while(true){
        if (x+i >= N) break;
        if (y+i >= M) break;
        if(A[x][y] == A[x+i][y] && A[x][y] == A[x][y+i] && A[x][y] == A[x+i][y+i]){
            ans = max(ans, i);
        }
        i++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            brute(i, j);
        }
    }
    cout << (ans+1) * (ans+1) << '\n';
    
    return 0;
}