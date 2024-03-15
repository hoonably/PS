#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int N, K;
int ans = 1e9;
int cnt = 0;
bool visited[200001];

int move(int loc, int num){
    if (num==0) return loc-1;
    if (num==1) return loc+1;
    return 2*loc;
}

void bfs(int start_node, int end_node){
    queue<pair<int,int>> q;
    q.push({start_node, 0});
    
    while (!q.empty()){
        
        auto [cur_node, dist] = q.front();
        q.pop();
        
        // 똑같은 지점에 도달하는 방법이 여러개 존재할 수 있으므로 pop한 후 방문 여부 확인
        visited[cur_node] = true;
        
        if (cur_node == end_node){
            if (dist < ans){
                ans = dist;
                cnt = 1;
            }
            else if (dist == ans){
                cnt++;
            }
            else {
                return;
            }
        }
        
        for (int i=0; i<3; i++){
            int next_node = move(cur_node, i);
            if ( next_node<0 || next_node > 2*K) continue;
            if (visited[next_node]) continue;
            q.push({next_node, dist+1});
        }
    }
    return;  // 도달 못했을 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    // 수빈이가 동생보다 더 큰 경우
    if (N>=K) {
        cout << N-K << '\n' << 1;
    }
    else {
        bfs(N, K);
        cout << ans << '\n' << cnt;
    }

    return 0;
}