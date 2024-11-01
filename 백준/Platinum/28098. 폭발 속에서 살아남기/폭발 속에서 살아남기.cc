#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;  // 1061109567

#define X first
#define Y second
using point = pair<double, double>;

istream& operator >>(istream& stream, point& in){ return stream >> in.first >> in.second; }
ostream& operator << (ostream &stream, const point &out) {return stream<<out.first<<" "<<out.second;}
point operator + (const point &A, const point &B){ return { A.X + B.X, A.Y + B.Y }; }
point operator - (const point &A, const point &B){ return { A.X - B.X, A.Y - B.Y }; }
auto operator * (const point &A, const point &B){ return A.X*A.X + A.Y*A.Y; }
auto operator / (const point &A, const point &B){ return A.X*B.Y - B.X*A.Y; }
point operator * (const point &A, double B){ return { A.X * B, A.Y * B }; }
point operator / (const point &A, double B){ return { A.X / B, A.Y / B }; }

int ccw(const point &A, const point &B, const point &C){
    auto res = (B - A) / (C - B);
    return (res > 0) - (res < 0);  // 1: 반시계, 0: 직선, -1: 시계
}
auto dist(point A, point B){  // 거리의 제곱
	auto dx = A.X - B.X;
	auto dy = A.Y - B.Y;
	return dx*dx + dy*dy;
}
int is_cross(point s1, point e1, point s2, point e2) {
	int ab = ccw(s1, e1, s2) * ccw(s1, e1, e2);
	int cd = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if (ab < 0 && cd < 0) return -1;  // 선분의 중간에서 cross
	if (ab == 0 && cd == 0) {
		if (s1 > e1) swap(s1, e1);
		if (s2 > e2) swap(s2, e2);
		return s2 <= e1 && s1 <= e2;
	}
	return ab <= 0 && cd <= 0;
}
// 어디서 교차하는지 Call by reference로 저장 (선분이 겹치면 return 0)
bool where_cross(point s1, point e1, point s2, point e2, point& res) {
    auto det = (e1 - s1) / (e2 - s2);
    if (abs(det)<1e-9) {
        if (s1 > e1) swap(s1, e1);
        if (s2 > e2) swap(s2, e2);
        if (e1 == s2) { res = s2; return 1; }  // 점 s2에서 만남
        if (e2 == s1) { res = s1; return 1; }  // 점 s1에서 만남
        return 0;  // 선분이 겹쳐 여러 점에서 만남
    }
    res.X = s1.X + (e1.X - s1.X) * ((s2 - s1) / (e2 - s2) * 1.0 / det);
    res.Y = s1.Y + (e1.Y - s1.Y) * ((s2 - s1) / (e2 - s2) * 1.0 / det);
    return 1;  // 한 점에서 만남
}
// 선분 l 위에 점 P가 있는가?
bool is_on_line(point l1, point l2, point P) { return ccw(l1, l2, P)==0 && min(l1, l2) <= P && P <= max(l1, l2); }

struct polygon {
	vector<point> dots;

	/* constructors */
	polygon(int N) {dots.resize(N);}
	polygon(vector<point> dots) : dots(dots) {}

	/* methods */
	void build_convex_hull() { //convex hull in O(nlogn), ccw(dots[i], dots[i + 1], dots[i + 2]) == 1
		if (dots.size() < 3) return;
		swap(dots[0], *min_element(dots.begin(), dots.end()));
		sort(dots.begin() + 1, dots.end(), [&](const point& A, const point& B) {
			int cw = ccw(dots[0], A, B);
			if (cw) return cw > 0;
			return dist(dots[0], A) < dist(dots[0], B);
		});
		vector<point> res;
		for (const auto& i : dots) {
			while (res.size() >= 2 && ccw(res[res.size() - 2], res.back(), i) <= 0) res.pop_back();
			res.push_back(i);
		}
		dots = res;
	}
	int point_in_polygon(point &A){  //O(qn)
		if (dots.size() < 3) return 0;
		int cnt = 0;
        point B = {INF, A.Y + 1};// 새로운 점
		for (int i = 0; i < dots.size(); i++) {
            point C = dots[i], D = dots[(i + 1) % dots.size()];
			if (is_cross(A, B, C, D) == -1) cnt++;
			if (is_on_line(C, D, A)) return -1;  // 다각형 선분 위
		}
		return cnt % 2;  // 홀수 : 다각형 내부
	}
	int point_in_convex(point &A){  //O(qlogn), must be "convex polygon"
		if (dots.size() < 3) return 0;
		if (A < dots[0] || ccw(dots[0], dots[1], A) < 0 || ccw(dots[0], dots.back(), A) > 0) return 0;
		if (ccw(dots[0], dots[1], A) == 0) return is_on_line(dots[0], dots[1], A) ? -1 : 0;
		if (ccw(dots[0], dots.back(), A) == 0) return is_on_line(dots[0], dots.back(), A) ? -1 : 0;
		int lo = 0, hi = dots.size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) >> 1;
			if (ccw(dots[0], dots[mid], A) > 0) lo = mid;
			else hi = mid;
		}
		int cw = ccw(dots[lo], dots[lo + 1], A);
		return cw ? cw > 0 ? 1 : 0 : -1;
	}
    bool contain(polygon &convex) {  // is convex contain convex?
        for(point i : convex.dots) if(!point_in_convex(i)) return false;
        return true;
    }
	double rotating_calipers() { //maximum distance in O(n), must be "convex polygon"
        if (dots.size() < 2) return 0;
		int n = dots.size();
		int l = 0, r = max_element(dots.begin(), dots.end()) - dots.begin();
		double ret = sqrt(dist(dots[l], dots[r]));
		for (int i = 0; i < n; i++) {
			if ((dots[(l + 1) % n] - dots[l]) * (dots[(r + 1) % n] - dots[r]) < 0) l = (l + 1) % n;
			else r = (r + 1) % n;
			ret = max(ret, sqrt(dist(dots[l], dots[r])));
		}
		return ret;
	}
	double area() {
		auto CCW = [&](point& A, point& B, point& C) -> int {
		    return (B.X - A.X) * (C.Y - B.Y) - (C.X - B.X) * (B.Y - A.Y);
		};
		int ret = 0;
		for (int i = 1; i < dots.size() - 1; i++) {
			ret += CCW(dots[0], dots[i], dots[i + 1]);
		}
		return abs(ret) / 2.;
	}
    // 선분을 리턴하는 함수
    vector<pair<point, point>> make_lines() const {
        vector<pair<point, point>> ret;
        for(int i=0; i<dots.size()-1; i++) ret.emplace_back(dots[i], dots[i+1]);
        if(dots.size() > 1) ret.emplace_back(dots.back(), dots[0]);
        return ret;
    }
};

/*
지금 볼록 다각형으로 만들면서 폭발지점을 몇개 없애서 틀림
(0,0) (-1,0) (1,0) 에서 터지면 (0,0)이 볼록 다각형의 점이 아니라서 무시됨...
*/

bool is_inside(const vector<point>& hull, const point& p) {
  int n = hull.size();
  if (n < 3) return false;

  if (ccw(hull[0], hull[1], p) <= 0 || ccw(hull[0], hull[n - 1], p) >= 0) return false;

  int lo = 1, hi = n - 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (ccw(hull[0], hull[mid], p) > 0) lo = mid;
    else hi = mid;
  }

  return ccw(hull[lo], hull[hi], p) > 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    polygon conv(N);
    for(point& p : conv.dots) cin >> p;
    conv.build_convex_hull();

    point me = {0, 0};
    

    // 현재 볼록다각형의 외부라면 바로 pass
    if (!is_inside(conv.dots, me)) {
        cout << "Yes\n";
        return 0;
    }
    // // 내부 : 각 선분의 중점까지 폭발보다 더 빠르게 달릴 수 있다면 pass
    // auto lines = conv.make_lines();
    // for(auto l : lines) {
    //     point mid = (l.first + l.second) / 2;
    //     if (dist(mid, me) + 1e-9 < dist(mid, l.first)){
    //         cout << "Yes\n";
    //         return 0;
    //     }
    // }
    cout << "No\n";
    
    return 0;
}