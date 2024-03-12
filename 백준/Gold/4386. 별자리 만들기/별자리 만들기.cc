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
5. 간선이 (노드-1)개라면 최소신장 트리 확정이라 break해도 됨
*/

vector<tuple<double,double,double>> v;
int parent[101];

struct dot {
    double x;
    double y;
};

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
    
    int n;
    cin >> n;
    dot dots[n];

    for (int i=0; i<n; i++){
        cin >> dots[i].x >> dots[i].y;
    }

    // 간선 (길이) 입력
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            v.push_back({dotDist(dots[i], dots[j]), i , j});
            // cout << dotDist(dots[i], dots[j]) << endl;
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    double ans = 0;
    int cnt = 0;
    for (auto edge : v){
        auto [cost, next, now] = edge;

        // 사이클이라면 PASS
        if (findParent(now) == findParent(next)) continue;

        unionParent(now, next);
        ans += cost;

        // 모든 정점을 연결하는 간선이 V-1개이면 바로 끝
        if (++cnt == n-1) break;
    }

    cout << ans;
    
    return 0;
}