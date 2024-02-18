#include <bits/stdc++.h>
using namespace std;

/*

*/

#define MAX 2187  // 3의 7제곱

int N;
int square[MAX][MAX];
int ans[3];

// 안되면 -2, 되면 그 색 반환
int check(int X1, int Y1, int size){
    int color = square[X1][Y1];
    for (int i=X1; i<X1+size; i++){
        for (int j=Y1; j<Y1+size; j++){
            if (square[i][j]!=color) return -2;
        }
    }
    return color;
}

void solve(int X1, int Y1, int size){
    int result = check(X1,Y1,size);
    if (result == -2){
        size /= 3;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                solve(X1+i*size,Y1+j*size,size);
            }
        }
    }
    else ans[result+1]++;  // 리스트로 올려주기
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> square[i][j];
        }
    }

    solve(0,0,N);
    cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
    
    return 0;
}