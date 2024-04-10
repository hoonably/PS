#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100000

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기

sort 과정에서 y, x가 작은순으로 하지 않고 거리가 작은 순으로 해준다.
*/

struct dot {
    ll x,y;
    bool operator<(dot const &p1) const {
        if (x!=p1.x) return x<p1.x;
        else return y<p1.y;
    }
};

ll ccw(dot a, dot b, dot c) {
    // 양수라면 반시계방향
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

ll dist(dot a, dot b){
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx*dx + dy*dy;
}

int N;
vector<dot> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
	cin >> N;

    // 그냥 push_back을 하면 할당 복사 해제 비용이 들어가 성능이 떨어짐

	// reserve(N) : N의 용량을 미리 확보해놓음.
	// resize(N, number) : N의 용량을 미리 확보해놓고
	// 나머지 공간을 두 번째 매개변수의 값으로 채움. 두 번째 매개변수가 없으면 0
    v.resize(N);
	for(int i=0; i<N; i++) cin >> v[i].x >> v[i].y;

	// 가장 작은 값을 맨 앞의 원소랑 바꿔줌 (x, y 순으로)
	swap(v[0], *min_element(v.begin(), v.end()));

	// 람다식을 이용한 sort
	sort(v.begin()+1, v.end(), [&](dot &a, dot &b){
        ll cc = ccw(v[0], a, b);
        if (cc) // 0 번 점을 기준으로 각도가 작은 순
            return cc > 0;
        return dist(v[0], a) < dist(v[0], b);
	});

	// Convex Hull
	vector<dot> CH;
	for(auto &i : v){
		while(CH.size() >= 2 && ccw(CH[CH.size()-2], CH.back(), i) <= 0) CH.pop_back();
		CH.push_back(i);
	}
	cout << CH.size() << "\n";
	// for(auto &i : CH) cout << i.x << " " << i.y << "\n";
    
    return 0;
}