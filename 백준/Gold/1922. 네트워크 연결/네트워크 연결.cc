#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1001

/*

*/

int V, E;
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

    int ans = 0, cnt = 0;
    for (auto edge : v){
        auto [cost, now, next] = edge;

        if (findParent(now) == findParent(next)) continue; // 이미 연결되어있다면 PASS

        unionParent(now, next);
        ans += cost;

        if (++cnt == V-1) {
            break;  // V-1개이면 바로 끝
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});  //가중치 오름차순 정렬 위해 c먼저
    }

    // 가중치 기준으로 정렬
    sort(v.begin(), v.end());

    // 최소 스패닝 트리 Minimum Spanning Tree
    cout << MST();
    
    return 0;
}