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
문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
문자열 S에는 0 ≤ i < j < N 이면서 s[i] == 'A' && s[j] == 'B'를 만족하는 (i, j) 쌍이 K개가 있다.
*/

#define MAX 

int N, K;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    // 최대인 경우
    if (K > N/2 * (N/2+(N%2))) {  // 홀수인 경우 ex) 7일때 3*4 = 12
        cout << -1;
        return 0;
    }

    // B를 N개 만든 뒤, 앞에서부터 차례로 A가 들어갈 수 있는 경우 A로 바꿈
    for(int i = 0, j = 1, sum = 0; i < N; i++) {
        if(N - j - i > 0 && sum + N - j - i <= K) {    
            cout << 'A';
            sum += N - j++ - i;
        }
        else cout << 'B';
    }
    
    return 0;
}