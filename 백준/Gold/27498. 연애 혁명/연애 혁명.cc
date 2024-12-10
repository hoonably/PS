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

struct Edge{
    int a, b, cost;
    // 최대 스패닝 트리 느낌
    bool operator<(const Edge &other) const {
        return cost > other.cost;
    }
};

int V, E;
vector<Edge> v;
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
    int ret = 0;
    for (auto edge : v){
        if (findParent(edge.a) == findParent(edge.b)) continue; // 이미 연결되어있다면 PASS
        unionParent(edge.a, edge.b);
        ret += edge.cost;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int Sum = 0;
    for(int i = 0; i < E; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d) {
            unionParent(a, b);
            continue;
        }
        v.push_back({a, b, c});  //가중치 오름차순 정렬 위해 c먼저
        Sum += c;
    }

    // 가중치 기준으로 정렬
    sort(v.begin(), v.end());

    // 최소 스패닝 트리 Minimum Spanning Tree
    cout << Sum - MST();
    
    return 0;
}