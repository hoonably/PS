#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 10001

/*

*/

int parent[MAX];
bool visited[MAX];

void solve(){

    int N;
    cin >> N;

    // 초기화
    for (int i=1; i<=N; i++){
        visited[i] = false;
        parent[i] = i;
    }

    // 간선정보 입력
    for (int i=0; i<N-1; i++){
        int A, B;
        cin >> A >> B;
        parent[B] = A;
    }

    // LCA 찾기
    int node1, node2;
    cin >> node1 >> node2;
    visited[node1] = true;

    // node1 부터 쭉 올라가면서 방문 체크
    while (node1 != parent[node1]){
        node1 = parent[node1];
        visited[node1] = true;
    }

    // node2 부터 올라가면서 node1의 parent인거 만나면 출력
    while (true){
        if (visited[node2]){
            cout << node2 << '\n';
            break;
        }
        node2 = parent[node2];
    }

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