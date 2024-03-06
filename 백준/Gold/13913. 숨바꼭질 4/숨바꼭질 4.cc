#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int N, K;
bool visited[100001];
int dist[100001];
int pre[100001];

int move(int loc, int num){
    if (num==0) return loc-1;
    if (num==1) return loc+1;
    return 2*loc;
}

int bfs(){
    queue<int> q;
    q.push(N);
        while (!q.empty()){
        
        int cur_node = q.front();
        int cur_dist = dist[cur_node];
        
        if (cur_node == K){
            return cur_dist;
        }

        q.pop();
        for (int i=0; i<3; i++){
            int next_node = move(cur_node, i);
            if ( next_node<0 || next_node>100000) continue;
            if (visited[next_node]) continue;
            visited[next_node] = true;
            dist[next_node] = cur_dist + 1;
            pre[next_node] = cur_node;
            q.push(next_node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    int ans = bfs();

    cout << ans << '\n';

    stack<int> st;
    for (int i=0; i<=ans; i++){
        st.push(K);
        K = pre[K];
    }
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
    
    return 0;
}