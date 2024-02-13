#include <bits/stdc++.h>
using namespace std;

/*
0으로 시작하지 않고
11이 두번연속으로 안나온다.

end_0[i] : 0이 마지막인 i자리 이친수의 개수
end_1[i] : 1이 마지막인 i자리 이친수의 개수
*/

long end_0[91] = {0, 0, 1, };
long end_1[91] = {0, 1, 0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=3; i<=N; i++){
        end_0[i] = end_0[i-1] + end_1[i-1];  // 0은 연속으로 나올 수 있음
        end_1[i] = end_0[i-1];  // 1이 나오려면 전에 0이여야함
    }
    cout << end_0[N] + end_1[N];
    
    return 0;
}