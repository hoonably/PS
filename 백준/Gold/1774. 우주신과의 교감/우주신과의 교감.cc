#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

struct dot {
    int x;
    int y;
};

vector<tuple<double,double,double>> v;
dot dots[1001];
int parent[1001];

double dotDist(dot A, dot B){
    double temp = pow(A.x - B.x, 2) + pow(A.y - B.y, 2);
    return sqrt(temp);
}

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
    
    int N, M;
    cin >> N >> M;

    for (int i=1; i<=N; i++){
        cin >> dots[i].x >> dots[i].y;
        parent[i] = i;
    }

    // 이미 연결된거 union
    for (int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        unionParent(s, e);
    }

    // 간선 (길이) 입력
    for (int i=1; i<N; i++){
        for (int j=i+1; j<=N; j++){
            v.push_back({dotDist(dots[i], dots[j]), i , j});
            // cout << dotDist(dots[i], dots[j]) << endl;
        }
    }
    sort(v.begin(), v.end());

    double ans = 0;
    int cnt = 0;
    for (auto edge : v){
        auto [cost, next, now] = edge;

        // 사이클이라면 PASS
        if (findParent(now) == findParent(next)) continue;

        unionParent(now, next);
        ans += cost;

        // 모든 정점을 연결하는 간선이 V-1개이면 바로 끝
        if (++cnt == N-1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;


    return 0;
}