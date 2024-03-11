#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*
모든 Node가 연결된다 + 가중치가 없다 -> MST다 -> MST의 조건은 간선의 개수가 Node-1개다
*/


void solve(){
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
    }
    cout << N-1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}