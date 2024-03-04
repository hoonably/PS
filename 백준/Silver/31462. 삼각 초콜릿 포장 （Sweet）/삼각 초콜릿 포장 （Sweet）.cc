#include <bits/stdc++.h>
using namespace std;

/*
위에서부터 내려가는 방식으로 그리디 알고리즘으로 접근하면 된다.
이미 묶어준 초콜릿은 0으로 바꿔주어 바로 넘긴다.

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {

            if (arr[i][j]=='0') continue;

            if (arr[i][j] == 'R') {
                if (i+1 >= n || j+1 > i+1) {
                    cout << 0;
                    return 0;
                }
                if (arr[i+1][j] != 'R' || arr[i+1][j+1] != 'R') {
                    cout << 0;
                    return 0;
                }
                arr[i][j] = arr[i+1][j] = arr[i+1][j+1] = '0';  // 완료 되었으면 0으로 표기
            }

            // 완료되지 않았는데 B가 나온 경우
            // (arr[i][j] == 'B')
            else {
                if (j+1 > i+1 || i+1 >= n) {
                    cout << 0;
                    return 0;
                }
                if (arr[i][j+1] != 'B' || arr[i+1][j+1] != 'B') {
                    cout << 0;
                    return 0;
                }
                arr[i][j] = arr[i][j+1] = arr[i+1][j+1] = '0';  // 완료 되었으면 0으로 표기
            }
        }
    }
    cout << 1;
}