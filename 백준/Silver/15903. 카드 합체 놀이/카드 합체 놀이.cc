#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
우선순위 큐를 사용하여 작은 두 수를 뽑자.
*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        ll num;
        cin >> num;
        pq.push(num);
    }

    for (int i=0; i<m; i++){
        ll a1 = pq.top(); pq.pop();
        ll a2 = pq.top(); pq.pop();
        pq.push(a1+a2);
        pq.push(a1+a2);
    }

    ll ans = 0;
    for (int i=0; i<n; i++){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    
    return 0;
}