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
https://www.acmicpc.net/problem/2141
*/

#define MAX 100'000

int N;
pll XA[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    ll a, b;
    
    ll people=0;
    for (int i=0; i<N; i++){
        cin >> XA[i].first >> XA[i].second;
        people += XA[i].second;
    }
    sort(XA, XA+N);

    ll cur=0;
    for (int i=0; i<N; i++){
        cur += XA[i].second;
        if (cur>=(people+1)/2){
            cout << XA[i].first;
            break;
        }
    }
    
    return 0;
}