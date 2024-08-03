#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/12989

길이가 n이며, 첫 m개의 소문자 알파벳만으로 이루어진 문자열 S가 주어진다. 
이때, 길이가 n이고 첫 m개의 알파벳만으로 이루어진 문자열들 중, 
S와의 LCS (Longest Common Subsequence)의 길이가 n-1인 문자열의 개수를 구하시오.
*/

#define MAX 

ll ans, cnt;
char ret, last=-1, last2=-2, c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    ans = 1;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        
        if (c == last2) cnt++;
        else cnt = 0;

        if (c != last) ans += n * (m - 1) - cnt - 1;

        last2 = last;
        last = c;
    }

    cout << ans;
    
    return 0;
}