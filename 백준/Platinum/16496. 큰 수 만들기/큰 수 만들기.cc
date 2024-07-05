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
    int zero = 0;  // 0의 개수
    for(int i=0; i<N; i++){
        string num;
        cin >> num;
        if (num != "0") v.push_back(num);
        else zero++;
    }

    // 0밖에 없었다면
    if (v.size()==0) {
        cout << '0';
        return 0;
    }

    sort(all(v), compare);

    for(string s : v){
        cout << s;
    }
    for(int i=0; i<zero; i++){
        cout << '0';
    }
    
    return 0;
}