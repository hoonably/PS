#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

const int MAXN = 10001;

void f(vector<int>& a, vector<int>& b) {
    for (int i = 1; i < 10000; i++) {

        // 각 자리수가 9부터 0까지인지 확인
        for (int x = 9; x >= 0; x--) {
            // a[0] * x * 2 + b[i] 의 1의 자리수가 x인지 확인
            if ((a[0] * x * 2 + b[i]) % 10 == x) {
                a[i] = x;
                break;
            }
        }

        // 큰 수 곱셈
        for (int j = 0; j <= i; j++) {
            b[i + j] += a[i] * a[j] * (j < i ? 2 : 1);
            b[i + j + 1] += b[i + j] / 10;
            b[i + j] %= 10;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<int> a5(MAXN << 1);
    vector<int> b5(MAXN << 1);  // a5 * a5

    a5[0] = 5;
    b5[0] = 5;
    b5[1] = 2;
    f(a5, b5);

    vector<int> a6(MAXN << 1);
    vector<int> b6(MAXN << 1);  // a6 * a6
    
    a6[0] = 6;
    b6[0] = 6;
    b6[1] = 3;
    f(a6, b6);

    // 높은 자리수부터 비교
    for (int i = n - 1; i >= 0; i--) {
        if (a5[i] > a6[i]) { cout << 5; break; }
        if (a5[i] < a6[i]) { cout << 6; break; }
    }
    
    return 0;
}