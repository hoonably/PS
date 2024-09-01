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
https://www.acmicpc.net/problem/1655
*/

#define MAX 

priority_queue<int> pq1;  // 최대 힙
priority_queue<int, vector<int>, greater<int>> pq2;  // 최소 힙

int sz1, sz2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        
        if (pq1.empty()) {
            pq1.emplace(num);
            ++sz1;
        } 
        else if (num<pq1.top()) {
            pq1.emplace(num);
            if (++sz1>sz2+1) {
                pq2.emplace(pq1.top()); pq1.pop();
                --sz1; ++sz2;
            }
        }
        else {
            pq2.emplace(num);
            if (sz1 < ++sz2){
                pq1.emplace(pq2.top()); pq2.pop();
                ++sz1; --sz2;
            }
        }
        cout << pq1.top() << '\n';
    }

    
    return 0;
}