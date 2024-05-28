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

#define MAX 100'000 

int N;
pii arr[MAX];
priority_queue<int, vector<int>, greater<int>> pq;  // 끝나는 시각

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        int num;
        cin >> num >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr+N);
    
    int ans = 1;
    pq.push(arr[0].second);
    for (int i=1; i<N; i++){
        // 빈 강의실 있음
        if (pq.top() <= arr[i].first) {
            pq.pop();
            pq.push(arr[i].second);
        }
        
        // 빈 강의실이 없어서 새로운 강의실 생성
        else {
            ans++;
            pq.push(arr[i].second);
        }
    }

    cout << ans;

    
    return 0;
}