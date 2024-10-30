#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
double dist(Point A, Point B){
	double dx = A.X - B.X;
	double dy = A.Y - B.Y;
	return sqrt(dx*dx + dy*dy);
}
// 선분 교차
int is_cross(Point a, Point b, Point c, Point d) { //cross : -1, intersect : 1
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);
		if (ab < 0 && cd < 0) return -1;
		if (ab == 0 && cd == 0) {
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);
			return c <= b && a <= d;
		}
		return ab <= 0 && cd <= 0;
	}
bool is_on_line(Point l1, Point l2, Point C) { return !ccw(l1, l2, C) && min(l1, l2) <= C && C <= max(l1, l2); }

struct polygon {
	vector<Point> v;
	/* constructors */
	polygon() {}
	polygon(vector<Point> v) : v(v) {}
	/* methods */
	void convex_hull() { //convex hull in O(nlogn), ccw(v[i], v[i + 1], v[i + 2]) == 1
		if (v.size() < 3) return;
		swap(v[0], *min_element(v.begin(), v.end()));
		sort(v.begin() + 1, v.end(), [&](const Point& A, const Point& B) {
			int cw = ccw(v[0], A, B);
			if (cw) return cw > 0;
			return dist(v[0], A) < dist(v[0], B);
		});
		vector<Point> res;
		for (const auto& i : v) {
			while (res.size() >= 2 && ccw(res[res.size() - 2], res.back(), i) <= 0) res.pop_back();
			res.push_back(i);
		}
		v = res;
	}
	double rotating_calipers() { //maximum distance in O(n), must be convex polygon
        if (v.size() < 2) return 0;
		int n = v.size();
		int l = 0, r = max_element(v.begin(), v.end()) - v.begin();
		double ret = sqrt(dist(v[l], v[r]));
		for (int i = 0; i < n; i++) {
			if ((v[(l + 1) % n] - v[l]) * (v[(r + 1) % n] - v[r]) < 0) l = (l + 1) % n;
			else r = (r + 1) % n;
			ret = max(ret, sqrt(dist(v[l], v[r])));
		}
		return ret;
	}
	int point_in_polygon_naive(Point A) { //O(qn), for all polygon, inside : 1, boundary : -1
		if (v.size() < 3) return 0;
		int cnt = 0;
        Point B = {1e9, A.Y + 1};// 새로운 점
		for (int i = 0; i < v.size(); i++) {
            Point C = v[i], D = v[(i + 1) % v.size()];  // 선분
			if (is_cross(A, B, C, D) == -1) cnt++;
			if (is_on_line(C, D, A)) return -1;
		}
		return cnt % 2;
	}
	double area() {
		auto CCW = [&](Point& A, Point& B, Point& C) -> int {
		    return (B.X - A.X) * (C.Y - B.Y) - (C.X - B.X) * (B.Y - A.Y);
		};
		int ret = 0;
		for (int i = 1; i < v.size() - 1; i++) {
			ret += CCW(v[0], v[i], v[i + 1]);
		}
		return abs(ret) / 2.;
	}
}poly;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    poly.v.resize(N);
    for(Point &i : poly.v) cin >> i;

    for(int i=0; i<3; i++){
        Point human;
        cin >> human;
        if (poly.point_in_polygon_naive(human)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}