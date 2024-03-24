#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX


/*
# 신발끈 정리

# 변의 길이가 다른 다각형 넓이 구하는 공식을 사용하면 된다.
# 다각형의 좌표를 쓴다.
# 반시계 방향 순서로 x와 y좌표를 리스트로 나열한 후 첫 꼭지점의 좌표를 맨 마지막에 하나 더 추가해준다.
# 각 꼭지점의 x좌표를 다음 꼭지점 좌표의 y값과 곱한 후 각 결과들을 더한다. - 결과1
# 반대로 각 y좌표 값을 다음 x좌표 값들과 곱하여 각 결과들을 더해준다. - 결과2
# (결과2 - 결과1) / 2 하면 다각형의 넓이가 나온다.
*/

struct dot {
    ll x;
    ll y;
};

int N, x, y;
vector<dot> dots;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        dots.push_back({x, y});
    }

    dots.push_back(dots[0]);  // 신발끈 정리를 위해서
    
    ll plus = 0;
    ll minus = 0;

    for (int i = 0; i < N; ++i) {
        plus += dots[i].x * dots[i + 1].y;
        minus += dots[i].y * dots[i + 1].x;
    }

    long double S = abs(plus - minus) / 2.0;

    cout << fixed;
    cout.precision(1);
    cout << S;
    
    return 0;
}