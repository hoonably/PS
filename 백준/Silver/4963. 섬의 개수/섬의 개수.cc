#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------
가로, 세로, 대각선으로 연결된 섬의 개수 구하기
*/

int w, h;
bool area[51][51];
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};

void dfs(int x, int y){
    if (x<0 || x>h || y<0 || y>w) return;
    if (!area[x][y]) return;
    area[x][y] = 0;
    for(auto ddx: dx) for(auto ddy: dy) {
        dfs(x + ddx, y + ddy);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true){
        cin >> w >> h;
        if (w==0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> area[i][j];
            }
        }

        int cnt = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if (area[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}