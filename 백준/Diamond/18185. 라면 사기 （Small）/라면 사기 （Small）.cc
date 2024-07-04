#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(A) A.begin(), A.end()
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
https://www.acmicpc.net/problem/18185

1개 3
2개 5
3개 7

4개 10
5개 12
6개 14

7개 17 ...
*/

#define MAX 10000

int N;
int A[MAX], cnt[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    // 첫번째 집 라면
    int ans = 3*A[0];

    // 두번째 집부터
    for (int i = 1; i < N; i++) {

        // 2연속 구매
        int buy = min(A[i], A[i-1]);
        A[i] -= buy;
        cnt[i] += buy;  // 다음 3연속 구매를 위해 저장
        ans += 2*buy;

        // 3개 연속 구매 (이전에 이미 2연속 구매)
        buy = min(A[i], cnt[i-1]);
        A[i] -= buy;
        ans += 2*buy;

        // 연속구매 못한것들 처리
        ans += 3*A[i];
    }

    cout << ans;
    
    return 0;
}