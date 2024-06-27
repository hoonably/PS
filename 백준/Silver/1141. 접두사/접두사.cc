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
https://www.acmicpc.net/problem/1141
*/

#define MAX 

int N;
string words[50];

bool match(string a, string b){
    if (a.length()>b.length()) return false;
    for(int i=0; i<a.length(); i++){
        if (a[i]!=b[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> words[i];
    }

    sort(words, words+N);

    int cnt = 0;
    for(int i=1; i<N; i++){
        if (match(words[i-1], words[i])){
            cnt++;
        }
    }
    
    cout << N-cnt;

    return 0;
}