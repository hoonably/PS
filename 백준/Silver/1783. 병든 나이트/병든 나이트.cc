#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
오른쪽으로만 갈 수 있는 병든 나이트.

가로줄에 몇개의 칸을 갈 수 있는지 체크
*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    // 세로가 한칸 (움직일 수 없음)
    if (N==1) cout << 1;

    // 세로가 두칸 (움직여도 위아래 한번씩만 가능)
    else if (N==2) cout << min(4, (M+1)/2);

    // 세로가 세칸 이상
    else{
        // 가로가 6 이하 : 최대 4칸
        if (M<=6) cout << min(4, M);

        // 
        else {
            cout << M-2;
        }
    }


    return 0;
}