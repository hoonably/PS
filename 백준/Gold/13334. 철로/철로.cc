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
https://www.acmicpc.net/problem/13334
*/

#define MAX 100'001

int n, d;
vector<pii> loc;
priority_queue<int, vector<int>, greater<int>> pq;

// 뒤에가 빠른 순으로 정렬
bool cmp(pii a, pii b){
    if (a.second==b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        int h, o;
        cin >> h >> o;
        if (h < o) loc.push_back({h,o});
        else loc.push_back({o,h});
    }
    sort(all(loc), cmp);

    cin >> d;
    int ans = 0;  // 한 선분에 포함될 수 있는 최대 인원수
    for(int i=0; i<n; i++){
        auto [s, e] = loc[i];
        if (e-s > d) continue;
        pq.emplace(s);

        // 최소 힙으로 기록된 s중에 작은거부터 차이가 d가 넘어가면 빼내기
        while(!pq.empty()){
            if (e - pq.top() > d) pq.pop();
            else {
                ans = max(ans, (int)pq.size());
                break;
            }
        }
    }
    cout << ans;
    
    return 0;
}