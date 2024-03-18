#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 301

/*
1. 모든 간선들의 가중치를 오름차순으로 정렬
2. 비용이 작은 간선 순으로 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 
    2개의 노드를 서로 연결하는 과정 반복
*/

int V, E;
int parent[MAX];
int cnt = 0;
vector<tuple<int,int,int>> v;
bool power[MAX];
int sons[MAX];  // 자녀의 개수 (자신 미포함)

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int MST(){
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    int ans = 0;
    for(auto edge : v){
        auto [cost, now, next] = edge;
        
        if (findParent(now) == findParent(next)) continue;
        unionParent(now, next);
        ans += cost;
    }

    // 아래 이거 해주면 안됨.
    // 임의의 가상 노드 0으로 모두 이어져야 하므로!!!
    // if (++cnt == V-1) return ans;  // V-1개이면 바로 끝

    return ans;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V;

    // 우물은 0으로
    for (int i=1; i<=V; i++){
        int cost;
        cin >> cost;
        v.push_back({cost, 0, i});
    }

    for (int i=1; i<=V; i++){
        for (int j=1; j<=V; j++){
            int cost;
            cin >> cost;
            if (i>=j) continue;
            v.push_back({cost, i, j});
        }
    }

    // 가중치 기준으로 정렬
    sort(v.begin(), v.end());

    // 최소 스패닝 트리 Minimum Spanning Tree
    cout << MST();
    
    return 0;
}