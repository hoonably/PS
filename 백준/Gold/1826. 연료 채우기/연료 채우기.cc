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

*/

#define MAX 10'001

int N, L, P;
pii oil[MAX];
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> oil[i].first >> oil[i].second;
    }
    sort(oil, oil+N);  

    cin >> L >> P;

    oil[N] = {L,0};  // 도착지

    int cnt = 0;

    for (int i=0; i<=N; i++){
        // 현재 기름으로 못간다면
        while (P < oil[i].first){

            // 다음 주유소에 절대 못감
            if (pq.empty()) {
                cout << "-1\n";
                return 0;
            }

            // 기름 주유
            P += pq.top();
            // cout << P << "\n";
            pq.pop();
            cnt++;
        };

        pq.push(oil[i].second);
    }
    
    cout << cnt;

    
    return 0;
}