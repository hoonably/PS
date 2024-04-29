#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 300'001

/*
i번째 칸의 보물상자를 열려면 높이 차이가 Bi보다 크거나 같아야함
dp[i] : i번째 칸까지 갔을 때 최대점수

이분탐색 활용해서 가능한 높이 구간 구하기

이분탐색 stl 활용하기 위해서 거꾸로 받기
*/

int N;
int H[MAX], A[MAX], B[MAX];
ll dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    for (int i=N; i>=1; i--){
        cin >> H[i];
    }
    for (int i=N-1; i>=1; i--){
        cin >> A[i];
    }
    for (int i=N-1; i>=1; i--){
        cin >> B[i];
    }

    ll ans = 0;
    for (int i=N-1; i>=1; i--){
        
        // i번째 상자를 부수기 위해 필요한 높이
        int needH = H[i]+B[i];

        // 시작지점에서 점프해도 상자 못부숨
        if (H[N]<needH) {
            dp[i] = dp[i+1];
            continue;
        }

        // 이진탐색으로 상자를 부술 수 있는 칸 중에서
        // 가장 낮은 칸 찾기
        int idx = lower_bound(H+i+1,H+N+1,needH) - H;

        dp[i] = max(dp[i+1], dp[idx]+A[i]); // 1번 ~ idx번 까지 중 최대값에서 점프
    }

    cout << dp[1];  // 1번계단까지 최대값
    
    return 0;
}