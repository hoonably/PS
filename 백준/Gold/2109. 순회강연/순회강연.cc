#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/2109

우선순위 큐 사용
우선순위 큐 사용 안하고 풀면 10배로 느림

하루에 한개의 강연을 할 수 있을때, 
마감일과 강연료가 주어진다.
강연료를 최대로 얻으려고 하면 얼마나 얻을 수 있는가?
*/

#define MAX 10001

int N;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> v;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	cin>>N;

    int p, d;
	for(int i=0;i<N;i++) {
		cin >> p >> d;
		v.push_back({d,p});  // 정렬 위해 기간 먼저
	}
	
    // 마감기간 오름차순 정렬
	sort(v.begin(), v.end());
	
    // 우선순위 큐에 넣기
	for(pii i: v){
		pq.push(i.second);

        // 기간 내에 일정 수가 마감기간보다 커진다면
        // 가장 가치가 작은 값 방출
		if (pq.size()>i.first) pq.pop();
	}
	
	while(!pq.empty()) {
		ans+=pq.top();
		pq.pop();
	}

	cout << ans;
    
    return 0;
}