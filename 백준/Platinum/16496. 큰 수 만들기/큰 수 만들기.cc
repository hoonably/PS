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
https://www.acmicpc.net/problem/16496
*/

#define MAX 

int N;
vector<string> v;

bool compare(string a, string b){
    return a + b > b + a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    v.resize(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    sort(all(v), compare);

    // 0밖에 없는 경우 정렬 후 앞에 0임
    if (v[0]=="0") {
        cout << "0";
        return 0;
    }

    for(int i=0; i<N; i++){
        cout << v[i];
    }
    
    return 0;
}