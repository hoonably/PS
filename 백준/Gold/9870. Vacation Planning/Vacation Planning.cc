#include <bits/stdc++.h>
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
const ll LINF = 10000000000L;
const int MOD = 1'000'000'007;

/*
< 플로이드 워셜 알고리즘 >
모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우
다익스트라에서 최단 거리 테이블에서 거리가 가장 짧은 노드를 탐색해야 했던 과정을 생략할 수 있다
시간복잡도 : O(N^3)
Dab = min(Dab, Dak + Dkb)
*/

int N, K, M, Q;
ll dist[205][205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K >> Q;
    fill(&dist[0][0], &dist[N+1][0], LINF);  // INF로 모두 초기화
    
    // 자기 자신 거리 0 초기화
    for (int i=1; i<=N; i++){
        dist[i][i] = 0;
    }

    for (int i=0; i<M; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        // 시작노드와 끝 노드가 같더라도 간선이 다를 경우 최저값 갱신
        dist[a][b] = min(dist[a][b], c);
    }

    // 허브를 반드시 지나가야함
    for (int k = 1; k <= N; k++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
            }
        }
    }

    // for (int a = 1; a <= N; a++) {
    //     for (int b = 1; b <= N; b++) {
    //         if (dist[a][b] == 1e9) cout << "0 ";
    //         else cout << dist[a][b] << ' ';
    //     }
    //     cout << '\n';
    // }

    int cnt = 0;
    ll ans = 0;
    for (int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;

        // 시작이나 끝 지점이 hub인 경우
        if(a <= K || b <= K){
            if(dist[a][b] != LINF){
                cnt++;
                ans += dist[a][b];
            }
        } 
        
        else {
            ll mini = LINF;

            for (int i = 1; i <= K; i++){
                mini = min(dist[a][i] + dist[i][b], mini);
            }

            if (mini != LINF){
                cnt++;
                ans += mini;
            }
        }
    }

    cout << cnt << '\n' << ans;

    return 0;
}