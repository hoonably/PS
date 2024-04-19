#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 101

/*

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
        assert(dots.size() >= 3 && "Can't make ConvexHull");
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

ConvexHull H1, H2, CH;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, M;
	cin >> N;
    vector<dot> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i].x >> A[i].y;
    }

    H1.build(A); 

    cin >> M;
    int cnt = 0;
    for (int i=0; i<M; i++){
        dot check;
        cin >> check.x >> check.y;
        if (H1.contain(check)){
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}