#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

int a, b, c;
int ab[100'000], bc[100'000], ca[100'000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        ab[i] = a + b;
        bc[i] = b + c;
        ca[i] = c + a;
    }
    // K개 선택했을 때 두 종류의 역량의 합의 최댓값
    sort(ab, ab+N, greater<int>());
    sort(bc, bc+N, greater<int>());
    sort(ca, ca+N, greater<int>());

    int maxab=0, maxbc=0, maxca=0;
    for(int i=0; i<K; i++){
        maxab += ab[i];
        maxbc += bc[i];
        maxca += ca[i];
    }
    cout << max({maxab, maxbc, maxca});
    
    return 0;
}