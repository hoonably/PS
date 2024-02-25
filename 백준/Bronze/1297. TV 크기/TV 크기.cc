#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
소수점이 나올 경우 버림 (int로 풀기)
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int D, H, W;
    cin >> D >> H >> W;
    
    // 52, 9, 16 일 경우
    // (9x)^2 + (16x)^2 = 52^2
    // x^2 = 52^2 / (9^2+16^2)
    // x = 52 / 루트 (9^2+16^2)
    
    // 이렇게 하면 틀림. (나누는 과정에서 버린 소수점이 오차를 일으킴)
    // double x = sqrt(D*D / (H*H + W*W));
    double x = D / sqrt(H*H + W*W);

    cout << (int)(H * x) << ' ' << (int)(W * x);
    
    return 0;
}