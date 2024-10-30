#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;  // 1061109567

#define X first
#define Y second
using Point = pair<double, double>;

istream& operator >>(istream& stream, Point& in){ return stream >> in.first >> in.second; }
ostream& operator << (ostream &out, const Point &d) {return out<<d.first<<" "<<d.second;}
Point operator + (const Point &a, const Point &b){ return { a.X + b.X, a.Y + b.Y }; }
Point operator - (const Point &a, const Point &b){ return { a.X - b.X, a.Y - b.Y }; }
auto operator * (const Point &a, const Point &b){ return a.X*a.X + a.Y*a.Y; }
auto operator / (const Point &a, const Point &b){ return a.X*b.Y - b.X*a.Y; }
Point operator * (const Point &a, double b){ return { a.X * b, a.Y * b }; }
Point operator / (const Point &a, double b){ return { a.X / b, a.Y / b }; }

int ccw(const Point &A, const Point &B, const Point &C){
    auto res = (B - A) / (C - B);
    return (res > 0) - (res < 0);  // 1: 반시계, 0: 직선, -1: 시계
}

// 선분 교차
bool cross(Point s1, Point e1, Point s2, Point e2){
    auto cw1 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    auto cw2 = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if(cw1 == 0 && cw2 == 0){
        if(e1 < s1) swap(s1, e1);
        if(e2 < s2) swap(s2, e2);
        return !(e1 < s2 || e2 < s1);
    }
    return cw1 <= 0 && cw2 <= 0;
}

// 어디서 교차하는지 Call by reference로 저장
int cross(Point s1, Point e1, Point s2, Point e2, pair<double,double>& res) {
    if (!cross(s1, e1, s2, e2)) return 0;
    auto det = (e1 - s1) / (e2 - s2);
    if (abs(det)<1e-9) {
        if (s1 > e1) swap(s1, e1);
        if (s2 > e2) swap(s2, e2);
        if (e1 == s2) { res = s2; return 1; }  // 점 s2에서 만남
        if (e2 == s1) { res = s1; return 1; }  // 점 s1에서 만남
        return INF;  // 여러 점에서 만남
    }
    res.X = s1.X + (e1.X - s1.X) * ((s2 - s1) / (e2 - s2) * 1.0 / det);
    res.Y = s1.Y + (e1.Y - s1.Y) * ((s2 - s1) / (e2 - s2) * 1.0 / det);
    return 1;  // 한 점에서 만남
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    int xmin, ymin, xmax, ymax;
    Point A1, A2, A3, A4, line1, line2;
    pair<double, double> meet;
    while(T--){
        //  A2   A4
        //  A1   A3
        cin >> xmin >> ymin >> xmax >> ymax;
        A1 = {xmin,ymin};
        A2 = {xmin,ymax};
        A3 = {xmax,ymin};
        A4 = {xmax,ymax};
        cin >> line1 >> line2;

        int ans = 0;
        int temp = cross(A1, A2, line1, line2, meet);
        if (temp==INF) {cout << "4\n"; continue;}
        if (temp && meet!=A1) ans++;

        temp = cross(A2, A4, line1, line2, meet);
        if (temp==INF) {cout << "4\n"; continue;}
        if (temp && meet!=A2) ans++;

        temp = cross(A4, A3, line1, line2, meet);
        if (temp==INF) {cout << "4\n"; continue;}
        if (temp && meet!=A4) ans++;

        temp = cross(A3, A1, line1, line2, meet);
        if (temp==INF) {cout << "4\n"; continue;}
        if (temp && meet!=A3) ans++;

        cout << ans << '\n';
    }
    
    return 0;
}