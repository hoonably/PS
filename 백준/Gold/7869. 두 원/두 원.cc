#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX


/*
두 원의 교차하는 영역의 넒이 구하기
*/

struct dot {
    double x;
    double y;
};

double dotDist(dot A, dot B){
    double temp = pow(A.x - B.x, 2) + pow(A.y - B.y, 2);
    return sqrt(temp);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    dot C1, C2;
    double r1, r2, ans;
    
    cin >> C1.x >> C1.y >> r1 >> C2.x >> C2.y >> r2;
    
    // 두 중심 사이의 거리
    double dist = dotDist(C1, C2);

    // 안 겹침
    if ((r1 + r2) <= dist) ans = 0;
    
    // 한 원이 다른 원의 내부
    else if (abs(r2 - r1) >= dist) {
        if (r1 < r2) ans = r1 * r1 * M_PI;
	    else ans = r2 * r2 * M_PI;
    }

    // 평범한 경우
    else {
        // 코사인 법칙
        double theta1 = acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist));
	    double theta2 = acos((r2 * r2 + dist * dist - r1 * r1) / (2 * r2 * dist));
	
        theta1 *= 2;
        theta2 *= 2;

        double S1 = (r1 * r1 * theta1 * 0.5) - (r1 * r1 * sin(theta1) * 0.5);
        double S2 = (r2 * r2 * theta2 * 0.5) - (r2 * r2 * sin(theta2) * 0.5);

        ans = S1 + S2;
    }

    cout<<fixed;
    cout.precision(3);
    cout << ans;

    return 0;
}