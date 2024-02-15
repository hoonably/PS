#include <bits/stdc++.h>
using namespace std;

/*
S[i] = 1~i의 합
i ~ j 번째 수 합 : S[j] - S[i-1]
연속합의 나머지가 1 0 0 1 0 일 경우
같은 수를 두개 고르면 그 사이의 부분합은 0으로 나누어 떨어짐.
combination 사용
0이 세번 나왔다면 3C2 + 3(0일 경우는 바로 그때 가능하기 때문에 추가계산)
1이 두번 나왔다면 2C2

++
잘 짰는데 또 데이터 형식 때문에 틀렸다.
combination을 구하는 상황에서 rest값 두개를 곱하는데,
rest값이 최대 10^6 이기 때문에 제곱을 하면 int범위를 넘는 10^12이 나올 수 있다.
*/

int N, M, num;
int sum = 0;  // 누적합 (나머지값)
long long rest[1000];  // 나머지는 최대 999
long long ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> N >> M;
    for (int i=1; i<=N; i++){
        cin >> num;
        sum = (sum+num)%M;

        // 0일 경우 본인 하나의 부분합이 가능하기 때문에 바로 1 추가
        // ex) 3항~3항까지
        if (sum==0) ans++;
        rest[sum]++;
    }


    for (int i=0; i<M; i++){
        // 2개 뽑는 combination 구하기
        ans += rest[i] * (rest[i]-1) / 2;
    }
    cout << ans;

    
    return 0;
}