#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
볼록 다각형 내부에 있다면 IMPOSSIBLE
외부에 있다면 탈출구로 볼록다각형 을 들어가지 않고 가는 최소거리
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

int n;
int nxt(int k){ return k+1 == n ? 0 : k+1; }  // 회전하면서 탐색할때 사용
int prv(int k){ return k == 0 ? n-1 : k-1; }

double ccw(const dot &p1, const dot &p2, const dot &p3){
    auto res = (p2 - p1) / (p3 - p2);
    return (res > 0) - (res < 0);
}

double dist(dot a, dot b){  // 거리의 제곰
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return dx*dx + dy*dy;
}

vector<dot> convexHull(vector<dot> &v){
    vector<dot> ret;
    swap(v[0], *min_element(v.begin(), v.end()));
    sort(v.begin()+1, v.end(), [&](const dot &a, const dot &b){
        auto cw = ccw(v[0], a, b);
        if(cw) return cw > 0;
        return dist(v[0], a) < dist(v[0], b);
    });
    for(const auto &i : v){
        while(ret.size() >= 2 && ccw(ret[ret.size()-2], ret.back(), i) <= 0) ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

bool valid(dot t, vector<dot> &v){
    bool flag = false;
    for(int i=0; i<n; i++){
        int j = i + 1; if(j == n) j = 0;
        if(ccw(v[i], v[j], t) <= 0) flag = true;
    }
    return flag;
}

void solve(){

    dot start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    
    cin >> n;
    vector<dot> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i].x >> v[i].y;
    }
    v = convexHull(v);

    // 불가능한지 판단 = 볼록다각형 내부에 점 존재
    if(!valid(start, v)){ cout << "IMPOSSIBLE\n"; return; }
    if(!valid(end, v)){ cout << "IMPOSSIBLE\n"; return; }

    // convexHull에 시작지점과 끝 지점도 넣어주고 다시 컨벡스 헐
    v.push_back(start); v.push_back(end);
    v = convexHull(v);

    n = v.size();

    int i, j;
    for(i=1; i<=n&&ccw(v[i-1], v[i%n], start)>0; i++);
    for(j=1; j<=n&&ccw(v[j-1], v[j%n], end)>0; j++);

    // 볼록 다각형을 안지나고 그냥 갈 수 있는 경우
    if(i == j || i > n || j > n){ 
        cout << sqrt(dist(start, end)) << "\n"; 
        return; 
    }

    i %= n; j %= n;
    
    // start -> i -> j -> end 인 경우
    double t1 = sqrt(dist(start, v[i])) + sqrt(dist(end, v[prv(j)]));
    for(int k=i; k!=prv(j); k=nxt(k)) t1 += sqrt(dist(v[k], v[nxt(k)]));

    // start -> j -> i -> end 인 경우
    double t2 = sqrt(dist(start, v[prv(i)])) + sqrt(dist(end, v[j]));
    for(int k=j; k!=prv(i); k=nxt(k)) t2 += sqrt(dist(v[k], v[nxt(k)]));

    cout << min(t1, t2) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cout << fixed << setprecision(3);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}