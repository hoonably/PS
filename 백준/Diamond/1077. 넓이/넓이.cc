#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 101

/*
이미 이 문제에서는 볼록 다각형의 꼭짓점이 반시계 방향 순서대로 주어진다.

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

// 선분이 교차하는지
bool Cross(dot s1, dot e1, dot s2, dot e2){
    auto cw1 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    auto cw2 = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if(cw1 == 0 && cw2 == 0){
        if(e1 < s1) swap(s1, e1);
        if(e2 < s2) swap(s2, e2);
        return !(e1 < s2 || e2 < s1);
    }
    return cw1 <= 0 && cw2 <= 0;
}

// 어디서 교차하는지 Call by reference로 알려줌
bool Cross(dot s1, dot e1, dot s2, dot e2, dot &res){
    if(!Cross(s1, e1, s2, e2)) return false;
    double det = (e1 - s1) / (e2 - s2);
    if(abs(det) < 1e-10) return false;  // 부동소수로 인한 0 이상 값 방지
    res = s1 + (e1 - s1) * ((s2 - s1) / (e2 - s2) / det);
    return true;
}

struct ConvexHull{
    vector<dot> pts;
    void build(vector<dot> a){
        swap(a[0], *min_element(a.begin(), a.end()));
        sort(a.begin()+1, a.end(), [&](const dot &s, const dot &e){
            double cw = ccw(a[0], s, e);
            if(cw != 0) return cw > 0;
            return dist(a[0], s) < dist(a[0], e);
        });
        pts.clear();
        for(auto i : a){
            while(pts.size() >= 2 && ccw(pts[pts.size()-2], pts.back(), i) <= 0) pts.pop_back();
            pts.push_back(i);
        }
        // assert(pts.size() >= 3);
    }
    bool contain(const dot &p) const {
        int i = lower_bound(pts.begin()+1, pts.end(), p, [&](const dot &a, const dot &b){
            double cw = ccw(pts[0], a, b);
            if(cw) return cw > 0;
            return dist(pts[0], a) < dist(pts[0], b);
        }) - pts.begin();
        if(i == pts.size()) return 0;
        if(i == 1) return ccw(pts[0], p, pts[1]) == 0 && pts[0] <= p && p <= pts[1];
        int t1 = ccw(pts[0], p, pts[i]) * ccw(pts[0], p, pts[i-1]);
        int t2 = ccw(pts[i], pts[i-1], pts[0]) * ccw(pts[i], pts[i-1], p);
        if(t1 == -1 && t2 == -1) return 0;
        return ccw(pts[0], p, pts[i-1]) != 0;
    }
    bool contain(const ConvexHull &h) const {
        for(const auto &i : h.pts) if(!contain(i)) return false;
        return true;
    }
    double area() const {
        double ret = 0;
        for(int i=0; i<pts.size(); i++){
            int j = i + 1; if(j == pts.size()) j = 0;
            ret += pts[i].x * pts[j].y;
            ret -= pts[j].x * pts[i].y;
        }
        return abs(ret) * 0.5;
    }
};

ConvexHull H1, H2, CH;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, M;
	cin >> N >> M;
    vector<dot> A(N), B(M), v;
    for (int i=0; i<N; i++){
        cin >> A[i].x >> A[i].y;
    }
    for (int i=0; i<M; i++){
        cin >> B[i].x >> B[i].y;
    }

    // A와 B를 ConvexHull 로 만들기
    H1.build(A); 
    H2.build(B);

    // 아예 한 도형이 다른 도형을 포함하고 있는지
    if(H1.contain(H2)){ cout << fixed << setprecision(12) << H2.area(); return 0; }
    if(H2.contain(H1)){ cout << fixed << setprecision(12) << H1.area(); return 0; }
    

    // 서로 교차하는 점 찾기
    A.push_back(A[0]);  // 선분 순환 위해서
    B.push_back(B[0]);  // 선분 순환 위해서
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            dot p;
            if(!Cross(A[i], A[i+1], B[j], B[j+1], p)) continue;
            v.push_back(p);
        }
    }
    A.pop_back();
    B.pop_back();

    // 다른 도형의 내부의 점 찾기
    for(auto i : H1.pts) if(H2.contain(i)) v.push_back(i);
    for(auto i : H2.pts) if(H1.contain(i)) v.push_back(i);
    
    if(v.empty()){ cout << 0; return 0; }

    // 새로운 볼록 껍질의 넓이 구하기
    CH.build(v);

    // cout << CH.pts.size() << " 각형 형성\n";
	// for(auto &i : CH.pts) cout << "(" << i.x << ", " << i.y << ")\n";

    cout << fixed << setprecision(12) << CH.area();
    
    return 0;
}