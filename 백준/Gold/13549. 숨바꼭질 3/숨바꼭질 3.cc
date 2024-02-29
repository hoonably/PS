#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

#define MAX 100000

int N, K;
bool visited[MAX+1];

int bfs(){
    deque<pair<int,int>> dq;
    dq.push_back({N,0});
    visited[N] = true;
    
    while(!dq.empty()){
        // auto [cur_node, dist] = dq.front();
        int cur_node = dq.front().first;
        int dist = dq.front().second;
        dq.pop_front();

        visited[cur_node]=true;

        if (cur_node==K) return dist;

		if(cur_node-1 > 0 && !visited[cur_node-1])
			dq.push_back({ cur_node-1, dist+1 });

		if(cur_node+1 <= MAX && !visited[cur_node+1])
			dq.push_back({ cur_node+1, dist+1 });

        // 순간이동 한 경우 push_front
		if(2*cur_node <= MAX && !visited[2*cur_node])
			dq.push_front({ 2*cur_node, dist });
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    if (N>=K){
        cout << N-K;
    }
    // N이 0일 경우에는 무한번 2를 곱해줄 수 있음
    // 먼저 1 더하고 시작해야함
    else if (N==0){
        N=1;  // 시작 1로
        cout << bfs()+1;
    }
    else{
        cout << bfs();
    }
    
    return 0;
}