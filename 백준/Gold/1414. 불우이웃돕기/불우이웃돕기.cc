#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 51

/*

*/

int N;
int sum = 0;
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

ll MST(){

    // N이 1인 경우
    // return sum - ans 가 발동이 안되므로 따로 처리
    if (N==1) return sum;


    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    ll ans = 0, cnt = 0;
    for (auto edge : v){
        auto [cost, now, next] = edge;

        if (findParent(now) == findParent(next)) continue; // 이미 연결되어있다면 PASS

        unionParent(now, next);
        ans += cost;

        // N이 1인경우 이게 안됨
        if (++cnt == N-1) return sum - ans;
    }

    return -1;  // MST가 완성되지 않음
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            char get;
            int cost;
            cin >> get;

            if (get=='0') continue;
            if (get>='a') cost = get - 'a' + 1;
            else cost = get - 'A'+ 27;

            sum += cost;

            v.push_back({cost, i, j});  // 하나씩만 저장
        }
    }

    // 가중치 기준으로 정렬
    sort(v.begin(), v.end());

    // 최소 스패닝 트리 Minimum Spanning Tree
    cout << MST();
    
    return 0;
}