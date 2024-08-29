#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 4'000'000

int N, M, K;
int parent[MAX];

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    // 큰 수로 union
    if (a<b) parent[a] = b;
    else parent[b] = a;
}

vector<int> Minsu;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    for (int i=0; i<M; i++){
        int m;
        cin >> m;
        Minsu.emplace_back(m);
    }
    sort(all(Minsu));

    // 인덱스 기준으로 parent 초기화
    for (int i=0; i<M; i++){
        parent[i]=i;
    }

    // 철수가 낼 카드
    for (int i=0; i<K; i++){
        int Chulsu;
        cin >> Chulsu;
        int idx = upper_bound(all(Minsu), Chulsu) - Minsu.begin();
        int par = findParent(idx);
        cout << Minsu[par] << '\n';

        unionParent(par, par+1);
    }
    
    return 0;
}