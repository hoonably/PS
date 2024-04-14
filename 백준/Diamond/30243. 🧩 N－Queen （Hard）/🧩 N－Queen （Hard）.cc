#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

int N;
ll alive, ldiag, rdiag;
int Q[30];
int step[30];
int ans[30];

bool backtracking(int m){
    if(m>N){
        return true;
    }
    ll bit = alive & ~((ldiag >> m)| (rdiag >> (N-m)));

    // 최하위 비트부터 모든 비트가 없어질때까지 하나씩 재귀
    for(ll a; bit!=0; bit ^= a){
        a = bit & (-bit);  // bit의 최하위 비트만을 가짐
        alive ^= a;
        ldiag ^= a << m; 
        rdiag ^= a << (N-m);
        if(backtracking(m + step[m])) {
            ans[m] = a;
            return true;
        }
        alive ^= a;
        ldiag ^= a << m; 
        rdiag ^= a << (N-m);
    } 
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    alive = (1 << N) - 1;
    N--;

    for(int j = 0; j <= N; ++j) {
        cin >> Q[j];
        if(Q[j]){
            ans[j] = 1 << (Q[j]-1);
            alive ^= 1ull << (Q[j] - 1);
            ldiag |= 1ull << (Q[j] - 1 + j);
            rdiag |= 1ull << (Q[j] - 1 + N - j);
        }
    }

    for(int i = 0; i <= N; ++i){
        if(Q[i]) continue;
        int s = 1;
        while(i + s <= N && Q[i+s]) ++s;
        step[i] = s;
    }
    
    int init = 0;
    while(init <= N && Q[init]) ++init;

    if(!backtracking(init)){
        cout << -1; return 0;
    }
    for(int i = 0; i <= N; ++i){
        int j = 0;
        while(1 << j < ans[i]) ++j;
        cout << j+1 << ' ';
    }
}