#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // 붙어있는 두변의 길이 합의 두배가 평행사변형의 둘레의 길이다.
    
    // 변의 길이 arr
    double len[3];
    len[0] = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    len[1] = sqrt(pow(x3-x2,2) + pow(y3-y2,2));
    len[2] = sqrt(pow(x3-x1,2) + pow(y3-y1,2));
    
    sort(len, len+3);
    
    // 세 점이 한 직선 위에 있는 경우
    // 아래 식으로 하면 부동소수점때문에 틀린다.
    // if (len[2]==len[0]+len[1]){
    //     cout << -1;
    //     exit(0);
    // }

    // 이것도 x 좌표 두개가 같다면 분모가 0이라서 다른 방법으로 확인해야한다.
    if (x1==x2 && x2==x3){
        cout << -1;
        exit(0);
    }
    
    else if ((y2-y1)/(x2-x1)==(y3-y2)/(x3-x2)){
        cout << -1;
        exit(0);
    }

    cout << fixed;
    cout.precision(10);
    cout << 2*(len[2]+len[1]) - 2*(len[0]+len[1]);
    
    return 0;
}