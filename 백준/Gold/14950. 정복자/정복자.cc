#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10001

/*
1. 모든 간선들의 가중치를 오름차순으로 정렬
2. 비용이 작은 간선 순으로 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 
    2개의 노드를 서로 연결하는 과정 반복
3. 간선이 (노드-1)개라면 MST이라 break해도 됨
*/

int V, E, t;
vector<tuple<int,int,int>> v;
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

int MST(){
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int ret = 0, cnt = 0;
    for (auto edge : v){
        auto [cost, now, next] = edge;

        if (findParent(now) == findParent(next)) continue; // 이미 연결되어있다면 PASS

        unionParent(now, next);
        ret += cost;

        if (++cnt == V-1) return ret;  // V-1개이면 바로 끝
    }

    return -1;  // MST가 완성되지 않음
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V >> E >> t;

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});  //가중치 오름차순 정렬 위해 c먼저
    }

    // 가중치 기준으로 정렬
    sort(v.begin(), v.end());

    // 최소 스패닝 트리 Minimum Spanning Tree
    cout << MST() + ((V-2) * (V-1) / 2 * t);
    
    return 0;
}