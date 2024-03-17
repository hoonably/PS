#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1001

/*

*/

int V, E, K;
int cnt = 0;
vector<tuple<int,int,int>> v;
bool power[MAX];
int parent[MAX];
int sons[MAX];  // 자녀의 개수 (자신 미포함)

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    // a가 발전기라면
    if (power[a]) {
        parent[b] = a;
        cnt += sons[b]+1;  // a가 부모인 것들의 개수 + a 본인
    }
    // b가 발전기라면
    else if (power[b]) {
        parent[a] = b;
        cnt += sons[a]+1;  // a가 부모인 것들의 개수 + a 본인
    }
    // 둘다 발전기가 아니라면
    else {
        parent[a] = b;
        sons[b] += sons[a]+1;  // a가 부모인 것들의 개수 + a 본인
    }
}

int MST(){
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int ans = 0;
    for (auto edge : v){
        auto [cost, now, next] = edge;

        int nowP = findParent(now);
        int nextP = findParent(next);


        if (nowP == nextP) continue; // 이미 연결되어있다면 PASS

        // 양쪽 다 Parent가 발전기라면 이을 필요가 없음
        if (power[nowP] && power[nextP]) continue;

        unionParent(now, next);
        ans += cost;

        if (cnt >= V-K) return ans;  // V-K개가 모두 발전소와 연결되었다면
    }

    return -1;  // MST가 완성되지 않음
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V >> E >> K;

    // 발전소 받기
    for (int i=0; i<K; i++){
        int num;
        cin >> num;
        power[num] = true;
    }

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