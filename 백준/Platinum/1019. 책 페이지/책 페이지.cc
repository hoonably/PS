#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
N = 283이라고 가정하고 생각해보겠습니다.

일단 0 ~ 2는 일의 자리에 28+1번씩 등장하게 되고, 이것은 N/10 + 1의 값에 해당합니다.

4 ~ 9는 일의 자리에 28번씩 등장하게 되고, 이것은 N/10의 값에 해당합니다.

3의 경우에는 아직은 28+1번 등장하는데, 다음 턴에서부터 Counting 기준이 달라집니다.



이번에는 10으로 나눈 뒤 원래 10의 자리에 위치했던 수들의 개수를 세봅시다.

0 ~ 7은 총 (2+1)×10회 등장함을 알 수 있고, 9는 2×10회 등장함을 알 수 있습니다.

그런데 8의 경우에는 280, 281, 282, 283의 4개의 숫자가 더 등장하므로 이들을 고려해서 추가로 Count 해주어야 합니다.

이제 이 과정을 N > 0인 조건 하에서 N을 10으로 계속 나눠주면서 반복하면 됩니다.
*/

ll cnt[10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    
    ll add = 0;

    for(int i=1; N!=0; i*=10) {
        int curr = N%10;
        N /= 10;

        // 0은 따로 i번째 자리면 i가 부족
        cnt[0] -= i;

        for(int j=0; j<curr; j++) cnt[j] += (N+1)*i;

        cnt[curr] += N*i + 1 + add;  // 현재는 add 도 더해줘야함

        for(int j=curr+1; j<=9; j++) cnt[j] += N*i;  // 이후

        add += curr*i;
    }

    for (int i=0; i<=9; i++){
        cout << cnt[i] << ' ';
    }

    return 0;
}