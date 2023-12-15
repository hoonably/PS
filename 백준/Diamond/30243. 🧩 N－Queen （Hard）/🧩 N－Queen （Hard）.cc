#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;

int n;
ull alive, ldiag, rdiag;
int step[30]{};
int ans[30]{};
bool recursive(int m){
    if(m>n){
        return true;
    }
    ull tmp = alive & ~((ldiag >> m)| (rdiag >> (n-m)));
    for(ull a;tmp;tmp ^= a){
        a = tmp & (-tmp);
        alive ^= a; ldiag ^= a << m; rdiag ^= a << (n-m);
        if(recursive(m + step[m])) {
            ans[m] = a;
            return true;
        } alive ^= a; ldiag ^= a << m; rdiag ^= a << (n-m);
    } return false;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if(n < 1) return 0;
    vector<int> q(n);
    alive = (1 << n) - 1;
    n--;
    for(int j = 0; j <= n; ++j) {
        auto &i = q[j]; cin >> i;
        if(i){
            ans[j] = 1 << (i-1);
            alive ^= 1ull << (i - 1);
            ldiag |= 1ull << (i - 1 + j);
            rdiag |= 1ull << (i - 1 + n - j);
        }
    }
    for(int i = 0; i <= n; ++i){
        if(q[i]) continue;
        int s = 1;
        while(i + s <= n && q[i+s]) ++s;
        step[i] = s;
    }
    int init = 0;
    while(init <= n && q[init]) ++init;

    bool finished = recursive(init);
    if(!finished){
        cout << -1; return 0;
    }
    for(int i = 0; i <= n; ++i){
        int j = 0;
        while(1 << j < ans[i]) ++j;
        cout << j+1 << ' ';
    }
}