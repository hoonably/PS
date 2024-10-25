#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100001

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기
볼록껍질을 구한 후, 볼록껍질끼리만 비교를 해주면 된다.

* 볼록껍질 순서를 반시계방향으로 함.

회전하는 캘리퍼스 알고리즘
1. 기준점 a를 정하고 다음 점 c를 정함
2. a에서 반시계방향으로 한칸 간 점이 b, c에서 반시계방향으로 한칸 간 점이 d

3~4 단계 반복
3. 벡터 ab 와 벡터 cd를 외적(ccw)했을때 양수(반시계 방향)라면 c를 다음으로
4. 반대로 음수(시계방향) 이면 더이상 가봤자 줄기 때문에 a를 다음 단계로

*/

#define x first
#define y second
using dot = pair<int, int>;

dot operator + (const dot &a, const dot &b){ return { a.x + b.x, a.y + b.y }; }
dot operator - (const dot &a, const dot &b){ return { a.x - b.x, a.y - b.y }; }
double operator * (const dot &a, const dot &b){ return a.x*a.x + a.y*a.y; }
double operator / (const dot &a, const dot &b){ return a.x*b.y - b.x*a.y; }
dot operator * (const dot &a, double b){ return { a.x * b, a.y * b }; }
dot operator / (const dot &a, double b){ return { a.x / b, a.y / b }; }

int ccw(const dot &p1, const dot &p2, const dot &p3){
    auto res = (p2 - p1) / (p3 - p2);
    return (res > 0) - (res < 0);
}
ll ccw2(dot A1, dot A2, dot B1, dot B2){
    return (A2.x-A1.x)*(B2.y-B1.y) - (A2.y-A1.y)*(B2.x-B1.x);
}

double dist(dot a, dot b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return dx*dx + dy*dy;
}
ll dist2(dot A, dot B){  // 거리의 제곱 연산
    ll dx = A.x-B.x;
    ll dy = A.y-B.y;
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
    void build(vector<dot> &a){
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
    // 회전하는 캘리퍼스
    double rotatingCallipers(){
        ll ans = 0;  // 불필요한 연산 방지를 위해 일단 제곱으로 저장 후 나중에 루트 씌우기
        int C = 1;
        int dotSZ = dots.size();
        for (int A=0; A<dotSZ; A++){
            // 양수(반시계 방향)라면 C를 높이기
            while(ccw2(dots[A], dots[(A+1)%dotSZ], dots[C], dots[(C+1)%dotSZ])>0){
                C = (C+1)%dotSZ;
            }
            // 시계방향이 된다면 더이상 C를 높여봤자 작아짐
            ans = max(ans, dist2(dots[A], dots[C]));  // 최대값 갱신 (이후에 A가 바뀜)
        }
        return sqrt(ans);
    }
};

ConvexHull CH;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N;
	cin >> N;
    vector<dot> v(N);
    for (int i=0; i<N; i++){
        cin >> v[i].x >> v[i].y;
    }
    CH.build(v);

    cout << fixed;
    cout.precision(9);
    cout << CH.rotatingCallipers();
    
    return 0;
}