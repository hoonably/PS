#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;  // 1061109567

#define X first
#define Y second
using Point = pair<double, double>;

istream& operator >>(istream& stream, Point& in){ return stream >> in.first >> in.second; }
ostream& operator << (ostream &out, const Point &d) {return out<<d.first<<" "<<d.second;}
Point operator + (const Point &A, const Point &B){ return { A.X + B.X, A.Y + B.Y }; }
Point operator - (const Point &A, const Point &B){ return { A.X - B.X, A.Y - B.Y }; }
auto operator * (const Point &A, const Point &B){ return A.X*A.X + A.Y*A.Y; }
auto operator / (const Point &A, const Point &B){ return A.X*B.Y - B.X*A.Y; }
Point operator * (const Point &A, double B){ return { A.X * B, A.Y * B }; }
Point operator / (const Point &A, double B){ return { A.X / B, A.Y / B }; }

int ccw(const Point &A, const Point &B, const Point &C){
    auto res = (B - A) / (C - B);
    return (res > 0) - (res < 0);  // 1: 반시계, 0: 직선, -1: 시계
}
ll dist(Point A, Point B){  // 거리의 제곱
	ll dx = A.X - B.X;
	ll dy = A.Y - B.Y;
	return dx*dx + dy*dy;
}
// 선분 교차
int is_cross(Point A, Point b, Point c, Point d) { //cross : -1, intersect : 1
		int ab = ccw(A, b, c) * ccw(A, b, d);
		int cd = ccw(c, d, A) * ccw(c, d, b);
		if (ab < 0 && cd < 0) return -1;
		if (ab == 0 && cd == 0) {
			if (A > b) swap(A, b);
			if (c > d) swap(c, d);
			return c <= b && A <= d;
		}
		return ab <= 0 && cd <= 0;
	}
bool is_on_line(Point l1, Point l2, Point C) { return ccw(l1, l2, C)==0 && min(l1, l2) <= C && C <= max(l1, l2); }

struct polygon {
	vector<Point> p;
	/* constructors */
	polygon(int N) {p.resize(N);}
	polygon(vector<Point> p) : p(p) {}
	/* methods */
	void convex_hull() { //convex hull in O(nlogn), ccw(p[i], p[i + 1], p[i + 2]) == 1
		if (p.size() < 3) return;
		swap(p[0], *min_element(p.begin(), p.end()));
		sort(p.begin() + 1, p.end(), [&](const Point& A, const Point& B) {
			int cw = ccw(p[0], A, B);
			if (cw) return cw > 0;
			return dist(p[0], A) < dist(p[0], B);
		});
		vector<Point> res;
		for (const auto& i : p) {
			while (res.size() >= 2 && ccw(res[res.size() - 2], res.back(), i) <= 0) res.pop_back();
			res.push_back(i);
		}
		p = res;
	}
	double rotating_calipers() { //maximum distance in O(n), must be "convex polygon"
        if (p.size() < 2) return 0;
		int n = p.size();
		int l = 0, r = max_element(p.begin(), p.end()) - p.begin();
		double ret = sqrt(dist(p[l], p[r]));
		for (int i = 0; i < n; i++) {
			if ((p[(l + 1) % n] - p[l]) * (p[(r + 1) % n] - p[r]) < 0) l = (l + 1) % n;
			else r = (r + 1) % n;
			ret = max(ret, sqrt(dist(p[l], p[r])));
		}
		return ret;
	}
	int point_in_polygon(Point A) { //O(qn), inside(선분 미포함): 1, boundary(선분 위): -1
		if (p.size() < 3) return 0;
		int cnt = 0;
        Point B = {INF, A.Y + 1};// 새로운 점
		for (int i = 0; i < p.size(); i++) {
            Point C = p[i], D = p[(i + 1) % p.size()];  // 선분
			if (is_cross(A, B, C, D) == -1) cnt++;
			if (is_on_line(C, D, A)) return -1;
		}
		return cnt % 2;
	}
	int point_in_convex(Point A) { //O(qlogn), for convex polygon only (볼록 다각형만)
		if (p.size() < 3) return 0;
		if (A < p[0] || ccw(p[0], p[1], A) < 0 || ccw(p[0], p.back(), A) > 0) return 0;
		if (ccw(p[0], p[1], A) == 0) return is_on_line(p[0], p[1], A) ? -1 : 0;
		if (ccw(p[0], p.back(), A) == 0) return is_on_line(p[0], p.back(), A) ? -1 : 0;
		int lo = 0, hi = p.size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) >> 1;
			if (ccw(p[0], p[mid], A) > 0) lo = mid;
			else hi = mid;
		}
		int cw = ccw(p[lo], p[lo + 1], A);
		return cw ? cw > 0 ? 1 : 0 : -1;
	}
	double area() {
		auto CCW = [&](Point& A, Point& B, Point& C) -> int {
		    return (B.X - A.X) * (C.Y - B.Y) - (C.X - B.X) * (B.Y - A.Y);
		};
		int ret = 0;
		for (int i = 1; i < p.size() - 1; i++) {
			ret += CCW(p[0], p[i], p[i + 1]);
		}
		return abs(ret) / 2.;
	}
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    polygon poly(N);
    for(Point &i : poly.p) cin >> i;

    for(int i=0; i<3; i++){
        Point human;
        cin >> human;
        if (poly.point_in_polygon(human)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}