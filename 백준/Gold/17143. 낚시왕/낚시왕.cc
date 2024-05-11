#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
벽에 부딫혔을 때 방향이 바뀌는 것도 생각해줘야함
*/

#define MAX 101

int R, C, M;
int speeds[10001], dirs[10001], sizes[10001];  // 속력, 이동방향, 크기
int board[MAX][MAX];  // 상어에 번호를 붙여서 번호로 표시
int temp[MAX][MAX];  // 복사용 temp

int moveUpDown(int r, int go, int &dir){
    int ret = r;
    if (dir==1){  // 위로
        ret -= go;
        if (ret<=0) {
            dir = 2;
            ret = moveUpDown(1, go-(r-1), dir);
        }
    }
    else{  // 아래로
        ret += go;
        if (ret > R){
            dir = 1;
            ret = moveUpDown(R, go-(R-r), dir);
        }
    }
    return ret;
}

int moveRightLeft(int c, int go, int &dir){
    int ret = c;
    if (dir==4){  // 왼쪽
        ret -= go;
        if (ret<=0) {
            dir = 3;
            ret = moveRightLeft(1, go-(c-1), dir);
        }
    }
    else{  // 오른쪽
        ret += go;
        if (ret > C){
            dir = 4;
            ret = moveRightLeft(C, go-(C-c), dir);
        }
    }
    return ret;
}

void moveAllShark(){
    // board => temp 복사
    for (int i=1; i<=R; i++)
        for (int j=1; j<=C; j++)
            temp[i][j] = board[i][j];

    // board 초기화
    memset(board, 0, sizeof(board));

    // temp 바탕으로 board 작성
    for (int i=1; i<=R; i++){
        for (int j=1; j<=C; j++){
            int nowShark = temp[i][j];
            if (nowShark!=0){
                int ni = i;
                int nj = j;
                if (dirs[nowShark]<=2) ni = moveUpDown(ni, speeds[nowShark], dirs[nowShark]);
                else nj = moveRightLeft(nj, speeds[nowShark], dirs[nowShark]);
                
                // 이동된 칸에 상어가 있는가? 있다면 크기 비교
                int &lastShark = board[ni][nj];
                if (lastShark==0) lastShark = nowShark;  // 비어있다면
                else {  // 상어가 있다면 비교 후 먹어서 바꾸기
                    if (sizes[nowShark]>sizes[lastShark]) lastShark = nowShark; 
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C >> M;

    for (int i=1; i<=M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        // speed 주기 나머지로 바꿔주기
        if (d<=2) s %= 2*(R-1);
        else s %= 2*(C-1);

        board[r][c] = i;
        speeds[i] = s;
        dirs[i] = d;
        sizes[i] = z;
    }

    int ans = 0;
    for (int human=1; human<=C; human++){

        // for (int i=1; i<=R; i++){
        //     for (int j=1; j<=C; j++){
        //         cout << board[i][j] << ' ';
        //     } cout << '\n';
        // } cout << '\n';

        // 가까운 상어 잡기
        for (int row=1; row<=R; row++){
            int &shark = board[row][human];
            if (shark!=0){
                ans+=sizes[shark];  // 상어 크기
                shark = 0;
                break;
            }
        }

        // 상어 이동
        moveAllShark();
    }
    cout << ans;
    
    return 0;
}