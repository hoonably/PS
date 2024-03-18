#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 301

/*
기준점은 0으로 연결시켜주자. 
대신 0도 노드에 포함이므로 V-1이 아니라 V까지
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

    parent[b] = a;
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

    if (++cnt == V) return ans;  // V개이면 바로 끝
    // 모두 0으로 이어지는것이므로 모두 물에 연결되는것임.

    return ans;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V;

    // 우물은 0으로 이어주는게 제일 중요!
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