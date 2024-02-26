#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

double W, H, X, Y, P;
int cnt = 0;

void solve(int nx, int ny){
    // 가운데 네모 내부
    if (X<=nx && nx<=X+W && Y<=ny && ny<=Y+H){
        cnt++;
        return;
    }
    // 첫번째 원 내부
    if ((X-nx)*(X-nx) + (Y+H/2-ny)*(Y+H/2-ny) <= (H/2)*(H/2)){
        cnt++;
        return;
    }
    // 두번째 원 내부
    if ((X+W-nx)*(X+W-nx) + (Y+H/2-ny)*(Y+H/2-ny) <= (H/2)*(H/2)){
        cnt++;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> W >> H >> X >> Y >> P;
    for (int i=0; i<P; i++){
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    cout << cnt;
    
    return 0;
}