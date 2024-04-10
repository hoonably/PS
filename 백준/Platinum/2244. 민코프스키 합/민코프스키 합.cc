#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 1000

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기

문제의 조건에 따라 sort 과정에서 y, x가 작은순으로 하지 않고 거리가 작은 순으로 해준다.
*/

struct dot {
    ll x,y;
    bool operator<(dot const &p1) const {
        if (x==p1.x){
            return y<p1.y;
        }
        else return x<p1.x;
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

int N, M;
dot A[MAX], B[MAX];
vector<dot> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
	cin >> N >> M;
	for(int i=0; i<N; i++) cin >> A[i].x >> A[i].y;
	for(int i=0; i<M; i++) cin >> B[i].x >> B[i].y;

	// 그냥 push_back을 하면 할당 복사 해제 비용이 들어가 성능이 떨어짐

	// reserve(N) : N의 용량을 미리 확보해놓음.
	// resize(N, number) : N의 용량을 미리 확보해놓고
	// 나머지 공간을 두 번째 매개변수의 값으로 채움. 두 번째 매개변수가 없으면 0
	v.reserve(N*M);

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			v.push_back({A[i].x+B[j].x, A[i].y+B[j].y});
		}
	}

	// 가장 작은 값을 맨 앞의 원소랑 바꿔줌 (x, y 순으로)
	swap(v[0], *min_element(v.begin(), v.end()));

	// 람다식을 이용한 sort
	sort(v.begin()+1, v.end(), [&](dot &a, dot &b){
		ll cw = ccw(v[0], a, b);
		if(cw) return cw > 0;
		// 중요!
		return dist(v[0], a) < dist(v[0], b);
	});

	// Convex Hull
	vector<dot> CH;
	for(auto &i : v){
		while(CH.size() >= 2 && ccw(CH[CH.size()-2], CH.back(), i) <= 0) CH.pop_back();
		CH.push_back(i);
	}
	cout << CH.size() << "\n";
	for(auto &i : CH) cout << i.x << " " << i.y << "\n";
    
    return 0;
}