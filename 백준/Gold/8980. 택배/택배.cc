#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/8980
보내는 마을 순으로 했다가 그러면 반례가 있어서 풀이 찾아봄
받는 마을 순으로 해야함

*/

#define MAX 

int N, C, M;
vector<tiii> graph;  // 주는 마을, 받는 마을, 
int truck[2001];

bool cmp(tiii a, tiii b){
    return get<1>(a) < get<1>(b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> C >> M;
    for (int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a, b, c});
    }

    sort(all(graph), cmp);

    int ans = 0;
    for (tiii node : graph){
        auto [from, to, box] = node;

        
        int maxi = 0;
        for (int i=from; i<to; i++){
            // 해당 마을에서 쌓인 박스 수 중 가장 큰 수
            maxi = max(maxi, truck[i]);
        }

        int now = 0;
        // 용량을 넘는 구간 이 없다면
        if (maxi + box <= C) now = box;
        // 용량을 넘는다면
        else now = C - maxi;

        for (int i=from; i<to; i++){
            truck[i] += now;
        }
        ans += now;
    }
    cout << ans;
    
    return 0;
}