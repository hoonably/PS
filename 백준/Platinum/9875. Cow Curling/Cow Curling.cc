#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 

/*
꼭 볼록 사각형이 만들어진다는 보장이 없음
+ 경계에 있는것도 포획으로 간주
*/

#define x first
#define y second
using dot = pair<double, double>;

dot operator + (const dot &a, const dot &b){ return { a.x + b.x, a.y + b.y }; }
dot operator - (const dot &a, const dot &b){ return { a.x - b.x, a.y - b.y }; }
double operator * (const dot &a, const dot &b){ return a.x*a.x + a.y*a.y; }
double operator / (const dot &a, const dot &b){ return a.x*b.y - b.x*a.y; }
dot operator * (const dot &a, double b){ return { a.x * b, a.y * b }; }
dot operator / (const dot &a, double b){ return { a.x / b, a.y / b }; }

double ccw(const dot &p1, const dot &p2, const dot &p3){
    auto res = (p2 - p1) / (p3 - p2);
    return (res > 0) - (res < 0);
}

double dist(dot a, dot b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return dx*dx + dy*dy;
}

struct ConvexHull{
    vector<dot> dots;
    bool build(vector<dot> a){
        swap(a[0], *min_element(a.begin(), a.end()));
        sort(a.begin()+1, a.end(), [&](const dot &s, const dot &e){
            double cw = ccw(a[0], s, e);
            if(cw != 0) return cw > 0;
            return dist(a[0], s) < dist(a[0], e);
        });
        dots.clear();
        for(auto i : a){
            while(dots.size() >= 2 && ccw(dots[dots.size()-2], dots.back(), i) <= 0) dots.pop_back();
            dots.push_back(i);
        }
        // 볼록 다각형이 만들어지지 않을 수 있음
        if (dots.size()<=2) return false;
        else return true;
    }
    // 다각형 내부에 점이 있는지
    bool contain(const dot &p) const {
        int i = lower_bound(dots.begin()+1, dots.end(), p, [&](const dot &a, const dot &b){
            double cw = ccw(dots[0], a, b);
            if(cw) return cw > 0;
            return dist(dots[0], a) < dist(dots[0], b);
        }) - dots.begin();
        if(i == dots.size()) return 0;
        if(i == 1) return ccw(dots[0], p, dots[1]) == 0 && dots[0] <= p && p <= dots[1];
        int t1 = ccw(dots[0], p, dots[i]) * ccw(dots[0], p, dots[i-1]);
        int t2 = ccw(dots[i], dots[i-1], dots[0]) * ccw(dots[i], dots[i-1], p);
        if(t1 == -1 && t2 == -1) return 0;
        return ccw(dots[0], p, dots[i-1]) != 0;
    }

    // 다각형이 안만들어졌을때 직선 내부에 점이 있는지
    bool containLine(const dot &p) const {
        if (dots[0] <= p && p <= dots[1]){
            if (ccw(dots[0], p, dots[1])==0) return true;
        }
        return false;
    }
};

ConvexHull H1, H2, CH;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N;
	cin >> N;
    vector<dot> A(N), B(N);
    for (int i=0; i<N; i++){
        cin >> A[i].x >> A[i].y;
    }
    for (int i=0; i<N; i++){
        cin >> B[i].x >> B[i].y;
    }

    // A와 B를 ConvexHull 로 만들고 점수 구하기

    int scoreA = 0, scoreB = 0;

    if (H1.build(A)) {  // 볼록다각형인 경우
        for (auto b : B) if (H1.contain(b)) scoreA++;
    }
    else {  // 직선인 경우
        for (auto b : B) if (H1.containLine(b)) scoreA++;
    }

    if (H2.build(B)){
        for (auto a : A) if (H2.contain(a)) scoreB++;
    }
    else {  // 직선인 경우
        for (auto a : A) if (H2.containLine(a)) scoreB++;
    }

    cout << scoreA << ' ' << scoreB;
    
    return 0;
}