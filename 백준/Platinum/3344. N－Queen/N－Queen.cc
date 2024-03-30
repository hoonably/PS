#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
알고리즘의 출처 : https://en.wikipedia.org/wiki/Eight_queens_puzzle
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    int col = 2;
    if (N % 6 == 2) {
        int cnt = N - 4;
        while (cnt > 0) {
            cout << col << '\n';
            col += 2;
            if (col > N) {
                cout << 3 << '\n';
                cout << 1 << '\n';
                col = 7;
            }
            cnt--;
        }
        cout << col << '\n';
        cout << 5 << '\n';
    } 
    
    else if (N % 6 == 3) {
        col = 4;
        int cnt = N - 3;
        while (cnt > 0) {
            cout << col << '\n';
            col += 2;
            if (col > N && col % 2 == 0) {
                cout << 2 << '\n';
                col = 5;
            }
            cnt--;
        }
        cout << 1 << '\n';
        cout << 3 << '\n';
    } 
    
    // 일반적인 케이스 (단순한 계단식)
    else {
        for (int i = 1; i <= N; ++i) {
            cout << col << '\n';
            col += 2;
            if (col > N) {
                col = 1;
            }
        }
    }
    
    return 0;
}