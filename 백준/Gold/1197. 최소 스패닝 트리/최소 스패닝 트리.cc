#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*
1. 모든 간선들의 가중치를 오름차순으로 정렬한다. 
2. 가중치가 가장 작은 간선을 선택한다.  
3. 2에서 선택한 간선이 연결하려는 2개의 노드가 
    아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.  
4. 위의 과정을 반복한다.
*/

int V, E;
vector<tuple<int,int,int>> v;
int parent[10001];

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        //가중치 오름차순 정렬 위해 c먼저
        v.push_back({c, a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int ans = 0, cnt = 0;
    for (auto edge : v){
        auto [cost, next, now] = edge;

        // 사이클이라면 PASS
        if (findParent(now) == findParent(next)) continue;

        unionParent(now, next);
        ans += cost;

        // 모든 정점을 연결하는 간선(V-1개)을 선택할때까지 반복
        if (++cnt == V-1) break;
    }

    cout << ans;
    
    
    return 0;
}