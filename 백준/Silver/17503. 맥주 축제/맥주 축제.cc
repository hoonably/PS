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
맥주 N개의 선호도 합이 M 이상이 되야하는 최소 간 레벨값을 구하기
*/

#define MAX 

int N, M, K;
vector<pii> vc;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;
    for(int i=0; i<K; i++) {
        int v, c; cin >> v >> c;
        vc.push_back({c,v});
    }
    sort(all(vc));

    
    priority_queue<int, vector<int>, greater<>> pq; // 맥주 담을 주머니
 
    ll sum = 0;
    for (auto beer : vc) {
        pq.push(beer.second);
        sum += beer.second;
 
        if (pq.size() > N) {
            sum -= pq.top(); // 가장 작은 선호도의 술을 빼기
            pq.pop();
        }

        if (pq.size() == N && sum >= M) {
            cout << beer.first;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}