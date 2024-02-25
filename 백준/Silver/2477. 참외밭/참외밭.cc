#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
동쪽은 1, 서쪽은 2, 남쪽은 3, 북쪽은 4
이동하는게 주어졌을때 6각형의 넓이 구하기
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int K;
    cin >> K;
    int dir[12], len[12];
    for (int i=0; i<6; i++){
        cin >> dir[i] >> len[i];
        dir[i+6]=dir[i];
        len[i+6]=len[i];
    }
    
    // 큰 직사각형에서 작은 직사각형을 빼주면 됨
    int biggest = 0;
    int big_idx = 0;
    for (int i=6; i<12; i++){
        int temp = len[i]*len[i-1];
        if (temp > biggest){
            biggest = temp;
            big_idx = i;
        }
    }
    cout << (biggest - len[big_idx-3] * len[big_idx-4]) * K;
    
    return 0;
}