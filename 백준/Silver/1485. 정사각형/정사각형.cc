#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

struct P {
    ll x, y;

    void read() {cin >> x >> y;}
};

double dist(P A, P B){
    ll dx = A.x-B.x;
    ll dy = A.y-B.y;
    return sqrt(dx*dx + dy*dy);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        P A, B, C, D;
        A.read(); B.read(); C.read(); D.read();

        // 기울기로 하지말고 모든 변의 길이와
        // 모든 대각선의 길이도 같다면 정사각형이다.

        // 변의 길이를 모두 나열했을때 가장 긴 두개가 대각선이다.
        double dists[6];
        dists[0]=dist(A,B);
        dists[1]=dist(A,C);
        dists[2]=dist(A,D);
        dists[3]=dist(B,C);
        dists[4]=dist(B,D);
        dists[5]=dist(C,D);

        sort(dists,dists+6);

        if (dists[4]==dists[5]
        && dists[0]==dists[1]
        && dists[0]==dists[2]
        && dists[0]==dists[3]
        && dists[3]!=dists[4]){
            cout << "1\n";
        }
        else cout << "0\n";
    }

    return 0;
}