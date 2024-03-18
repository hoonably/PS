#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1001

/*
1. 모든 간선들의 가중치를 오름차순으로 정렬
2. 비용이 작은 간선 순으로 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 
    2개의 노드를 서로 연결하는 과정 반복
3. 간선이 (노드-1)개라면 MST이라 break해도 됨
*/

int V, E, firstGo;
vector<pair<int,int>> v[2];
int parent[MAX];

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int low_MST(){
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (auto edge : v[1]){
        auto [now, next] = edge;

        if (findParent(now) == findParent(next)) continue; // 이미 연결되어있다면 PASS

        unionParent(now, next);

        if (++cnt == V-1) break;  // V-1개이면 바로 끝
    }

    return (V-1) - cnt + (firstGo^1);
}

// 오르막길
int high_MST(){
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    int cnt = 0;

    for (auto edge : v[0]){
        auto [now, next] = edge;

        if (findParent(now) == findParent(next)) continue; // 이미 연결되어있다면 PASS

        unionParent(now, next);

        if (++cnt == V-1) break;  // V-1개이면 바로 끝
    }

    return cnt + (firstGo^1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V >> E;

    int a, b, c;
    cin >> a >> b >> firstGo;

    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        v[c].push_back({a, b});
    }

    // 최소 스패닝 트리 Minimum Spanning Tree
    int best = low_MST();
    int worst = high_MST();
    // cout << low_MST() << ' ' << high_MST();
    cout << worst*worst - best*best;
    
    return 0;
}