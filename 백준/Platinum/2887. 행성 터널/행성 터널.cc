#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

/*
모든 행성들 간에 서로 X, Y, Z 좌표값 차이를 구해서 
간선의 가중치 정보로 넣는 방법을 생각할 수 있지만,
이 문제에서는 행성이 최대 10만개 주어지므로 
대략 10만*10만 만큼의 비교 및 데이터가 발생
- > 메모리 초과

어차피 X, Y, Z 좌표 끼리의 차의 최소값이므로
X, Y, Z를 따로 저장해서 정렬 후 입력

이렇게 하면 굳이 필요없는 모든 것들을 입력할 필요가 없음.

ex) X 좌표가 1, 3, 6 이라면
1,3 거리인 2 / 3,6 거리인 3 입력
1, 6 거리는 입력 안함
*/

int N;
vector<tuple<int,int,int>> v;
int parent[MAX];

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

ll MST(){
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    ll ans = 0;
    int cnt = 0;
    for (auto edge : v){
        auto [cost, now, next] = edge;

        if (findParent(now) == findParent(next)) continue; // 이미 연결되어있다면 PASS

        unionParent(now, next);
        ans += cost;

        if (++cnt == N-1) return ans;  // N-1개이면 바로 끝
    }

    return -1;  // MST가 완성되지 않음
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    for (int i=1; i<=N; i++){
        int x, y, z;
		cin >> x >> y >> z;
		X.push_back({x, i});
		Y.push_back({y, i});
		Z.push_back({z, i});
    }

    // 가중치 기준으로 각각 정렬
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

    // 가중치, 노드1, 노드2 입력
    for (int i=0; i<N-1; i++){
        v.push_back({X[i+1].first - X[i].first, X[i].second, X[i+1].second});
        v.push_back({Y[i+1].first - Y[i].first, Y[i].second, Y[i+1].second});
        v.push_back({Z[i+1].first - Z[i].first, Z[i].second, Z[i+1].second});
    }

    sort(v.begin(), v.end());

    // 최소 스패닝 트리 Minimum Spanning Tree
    cout << MST();
    
    return 0;
}