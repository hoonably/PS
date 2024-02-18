#include <bits/stdc++.h>
using namespace std;

/*

*/

int N;
int square[128][128];
int blue = 0, white = 0;

// 안되면 -1, 되면 그 색 반환
int check(int X1, int Y1, int size){
    int color = square[X1][Y1];
    for (int i=X1; i<X1+size; i++){
        for (int j=Y1; j<Y1+size; j++){
            if (square[i][j]!=color) return -1;
        }
    }
    return color;
}

void solve(int X1, int Y1, int size){
    int result = check(X1,Y1,size);
    if (result == 1) blue++;
    else if (result == 0) white++;
    else {
        size /= 2;
        solve(X1,Y1,size);
        solve(X1+size,Y1,size);
        solve(X1,Y1+size,size);
        solve(X1+size,Y1+size,size);
    }
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
    cout << white << '\n' << blue;
    
    return 0;
}