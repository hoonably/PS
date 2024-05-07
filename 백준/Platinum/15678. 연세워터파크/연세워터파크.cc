#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
dp 최대값만을 덱에 저장하면서 dp 갱신
시작지점을 본인이 선택하는거임. 그게 어려움
*/

#define MAX 100'001

int N, D;
ll num;
deque<pll> dq;  // dp 저장

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> D;

    ll ret = -LINF;

    // -1 인덱스로 0 넣어줌
    dq.push_back({-1,0});

    for (int i=0; i<N; i++) {
        cin >> num;

        while (dq.front().first < i - D) 
            dq.pop_front();

        // 구간 내 최대 dp가 양수라면 더함
        if (dq.front().second > 0)
            num += dq.front().second;

        // 최대값만 남기고 다 지움
        while (!dq.empty() && dq.back().second <= num)
            dq.pop_back();

        ret = max(ret, num);
        dq.push_back({i,num});
    }
    cout << ret << endl;
    
    return 0;
}