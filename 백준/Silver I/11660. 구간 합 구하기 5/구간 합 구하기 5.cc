#include <bits/stdc++.h>
using namespace std;

/*
S[i][j] = j번째 줄의 1~i의 합

arr 
1 2 
2 3

S (사각합)
1 3
3 5 -> S[2][2]를 구하는 법 : S[2][1]  +  S[1][2]   - S[1][1] + A[2][2]
                        자신의 왼쪽합 + 자신의 위쪽 합 - 겹치는 합 + 자기 자신

상상도 못한 오류 발생
C++ 에서 bits/stdc++.h 사용시 변수명을 x1 y1으로 하면 오류가 발생한다! ㅜㅜ
*/

int N, M, num, x_1, x_2, y_1, y_2;
int S[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> num;
            //       자신의 왼쪽합 + 자신의 위쪽 합 - 겹치는 합 + 자기 자신
            S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + num;
        }
    }
    while(M--){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << S[x_2][y_2] - S[x_2][y_1-1] - S[x_1-1][y_2] + S[x_1-1][y_1-1] << '\n';
    }
    
    return 0;
}