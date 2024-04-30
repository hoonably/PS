#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX 500'000

/*
https://www.acmicpc.net/problem/2012

*/

int N;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    v.resize(N);
    FOR(i,0,N){
        cin >> v[i];
    }

    sort(all(v));

    ll ans = 0;
    FOR(i,0,N){
        // 예측 - 실제 순위
        ans += abs(v[i] - (i+1));
    }
    cout << ans;
    
    return 0;
}