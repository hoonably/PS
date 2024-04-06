#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int l_x1, l_y1, r_x1, r_y1;
    int l_x2, l_y2, r_x2, r_y2;
    cin >> l_x1 >> l_y1 >> r_x1 >> r_y1;
    cin >> l_x2 >> l_y2 >> r_x2 >> r_y2;

    // 좌측하단 꼭지점이 더 좌측에 있는 사각형이 1번
    if(l_x1 > l_x2) {
        swap(l_x1, l_x2);
        swap(l_y1, l_y2);
        swap(r_x1, r_x2);
        swap(r_y1, r_y2);
    }

    // 왼쪽 사각형의 우측면과, 오른쪽 사각형의 좌측면이 같은 x값일때
    if(r_x1 == l_x2) {
        // 왼쪽 사각형 우측상단 점과, 오른쪽 사각형 좌측하단 점이 같을때 or
        // 왼쪽 사각형 우측하단 점과, 오른짝 사각형 좌측상단 점이 같을때 POINT
        if(r_y1 == l_y2 || l_y1 == r_y2) cout << "POINT";
            // 왼쪽 사각형의 윗면이, 오른쪽 사각형의 아랫면보다 아래 있을때
        else if(l_y2 > r_y1) cout << "NULL";
            // 왼쪽 사각형의 아랫면이, 오른쪽 사각형의 윗면보다 위에 있을때
        else if(l_y1 > r_y2) cout << "NULL";
        else cout << "LINE";
    }
        // 오른쪽 사각형의 왼쪽면이, 왼쪽 사각형의 오른쪽 면보다 왼쪽에 있을 경우
    else if(r_x1 > l_x2) {
        // 왼쪽 사각형의 윗면과, 오른쪽 사각형의 아랫면이 같을떄
        if(r_y1 == l_y2) cout << "LINE";
            // 왼쪽 사각형의 아랫면과, 오른쪽 사각형의 윗면이 같을때
        else if(l_y1 == r_y2) cout << "LINE";
            // 왼쪽 사각형의 윗면이, 오른쪽 사각형의 아랫면보다 아래 있을때
        else if(r_y1 < l_y2) cout << "NULL";
            // 왼쪽 사각형의 아랫면이, 오른쪽 사각형의 윗면보다 위에 있을때
        else if(l_y1 > r_y2) cout << "NULL";
        else cout << "FACE";
    }
        // 왼쪽 사각형의 오른쪽면이, 오른쪽 사각형의 왼쪽면보다 왼쪽에 있을때
    else
        cout << "NULL";


    return 0;
}