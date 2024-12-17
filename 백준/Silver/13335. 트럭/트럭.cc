#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, w, L; cin >> n >> w >> L;
    vector<int> truck(n);
    for(int i=0; i<n; i++) cin >> truck[i];

    queue<int> q;
    int sum = 0, time = 0;
    for(int i=0; i<n; i++){

        // 같이 움직이는 트럭들을 처리
        while(1){
            if(q.size() == w){
                sum -= q.front();
                q.pop();
            }
            if(sum + truck[i] <= L) break;
            q.push(0);
            time++;
        }
        q.push(truck[i]);
        sum += truck[i];
        time++;
    }
    cout << time + w;
    
    return 0;
}