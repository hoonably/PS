#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 

/*
울타리의 꼭짓점이 각 점보다 최소 L만큼 떨어지도록 그려야 한다.
모든 점에 +-L 을 해주고 둘레를 구하면 된다.

로 해도 되지만 훨씬 빠른 방법이 있다.

4방향에 대각선이 들어가기 때문에
4*sqrt(2)*l 를 더해주면 된다.
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
    vector<dot> dots;
    void build(vector<dot> a){
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
        // assert 함수는 size가 2 이하라면 다각형이 안만들어지므로 오류 발생
        // assert(dots.size() >= 3 && "Can't make ConvexHull");
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
    // 다각형 내부에 다각형이 있는지
    bool contain(const ConvexHull &h) const {
        for(const auto &i : h.dots) if(!contain(i)) return false;
        return true;
    }
    // 넓이를 리턴하는 함수
    double area() const {
        double ret = 0;
        for(int i=0; i<dots.size(); i++){
            int j = i + 1; if(j == dots.size()) j = 0;
            ret += dots[i].x * dots[j].y;
            ret -= dots[j].x * dots[i].y;
        }
        return abs(ret) * 0.5;
    }
    // 선분을 리턴하는 함수
    vector<pair<dot, dot>> makeEdges() const {
        vector<pair<dot, dot>> ret;
        for(int i=0; i+1<dots.size(); i++) ret.emplace_back(dots[i], dots[i+1]);
        if(dots.size() > 1) ret.emplace_back(dots.back(), dots[0]);
        return ret;
    }
};

ConvexHull CH;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, L;
    cin >> N >> L;

    vector<dot> v(N);
    for (int i=0; i<N; i++){
        cin >> v[i].x >> v[i].y;
    }


    CH.build(v);

    // 선분 벡터
    auto Edges = CH.makeEdges();

    double ans = 4*sqrt(2)*L;
    for (auto &e : Edges){
        ans += sqrt(dist(e.first, e.second));
    }
    cout << fixed << setprecision(9) << ans;
    
    return 0;
}