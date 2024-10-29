#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
using dot = pair<ll, ll>;

dot operator + (const dot &a, const dot &b){ return { a.x + b.x, a.y + b.y }; }
dot operator - (const dot &a, const dot &b){ return { a.x - b.x, a.y - b.y }; }
double operator * (const dot &a, const dot &b){ return a.x*a.x + a.y*a.y; }
double operator / (const dot &a, const dot &b){ return a.x*b.y - b.x*a.y; }
dot operator * (const dot &a, double b){ return { a.x * b, a.y * b }; }
dot operator / (const dot &a, double b){ return { a.x / b, a.y / b }; }

int ccw(const dot &A, const dot &B, const dot &C){
    auto res = (B - A) / (C - B);
    return (res > 0) - (res < 0);
}

// 선분 교차 : 선분 A, 선분 B가 교차하는가?
bool Cross(dot A1, dot A2, dot B1, dot B2){
    auto cw1 = ccw(A1, A2, B1) * ccw(A1, A2, B2);
    auto cw2 = ccw(B1, B2, A1) * ccw(B1, B2, A2);
    if(cw1 == 0 && cw2 == 0){
        if(A2 < A1) swap(A1, A2);
        if(B2 < B1) swap(B1, B2);
        return !(A2 < B1 || B2 < A1);
    }
    return cw1 <= 0 && cw2 <= 0;
}

// 어디서 교차하는지 Call by reference로 저장
bool Cross(dot A1, dot A2, dot B1, dot B2, dot &res){
    if(!Cross(A1, A2, B1, B2)) return false;
    auto det = (A2 - A1) / (B2 - B1);
    if(abs(det) < 1e-10) return false;  // 부동소수로 인한 0 이상 값 방지
    res = A1 + (A2 - A1) * ((B1 - A1) / (B2 - B1) / det);
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dot A1, A2, B1, B2;
    cin >> A1.first >> A1.second;
    cin >> A2.first >> A2.second;
    cin >> B1.first >> B1.second;
    cin >> B2.first >> B2.second;

    cout << Cross(A1, A2, B1, B2);

    
    return 0;
}