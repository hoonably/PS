#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200001

/*

*/

vector<tuple<int, int, int>> v;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while (true){
        
        v.clear();

        int m, n;
        cin >> m >> n;

        if (m==0) break;

        int ans=0;
        for (int i=0; i<n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            v.push_back({z, x, y});
            ans += z;
        }

        sort(v.begin(), v.end());

        for (int i=0; i<m; i++){
            parent[i] = i;
        }

        int cnt = 0;
        // 발상의 전환
        // 어차피 모두 이어져야 하는데, 절약을 최대한 안하려면
        // 그냥 최소 스패닝 트리를 만들고 전체에서 빼면 그게 절약한 금액
        for (auto edge : v){
            auto [cost, next, now] = edge;

            // 사이클이라면 PASS
            if (findParent(now) == findParent(next)) continue;

            unionParent(now, next);
            ans -= cost;

            // 모든 정점을 연결하는 간선이 V-1개이면 MST 이므로 끝
            if (++cnt == m-1) break;
        }
        cout << ans << '\n';
    }
    
    return 0;
}