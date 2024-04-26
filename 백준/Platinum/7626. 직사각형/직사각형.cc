#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 200'000

/*
3392 화성지도 먼저 풀어보고 오기
이 문제는 좌표 압축까지 추가된 문제

x축 기준으로 정렬

y축 점들 세그먼트 트리에 저장
점이 시작하는 점이라면 세그먼트 트리에 1을 더하고, 
끝나는 점이라면 -1을 더하면 된다.

이러면 겹치는 부분 넓이를 구할 수도 있음
=> 세그먼트 트리를 2개 활용

하나는 구간에 점이 몇개가 있는지를 저장
하나는 점이 있는지 유무만 확인
*/

struct T {
    int x, y1, y2, finish;
    // finish가  1 : x가 시작 지점
    // finish가 -1 : x가 끝 지점

    T(int x, int y1, int y2, int finish){  // 생성자
        this->x = x; this->y1=y1; this->y2=y2; this->finish=finish;
    }

    // x기준 정렬 위한 operator 연산자
    bool operator < (const T & y1) const {
        return this->x < y1.x;
    }
};

int N;
vector<T> v;
vector<int> yCom;

vector<int> cnt;
vector<ll> segTree;

// qs ~ qe val만큼 더해주기
void update(int node, int s, int e, int qs, int qe, int val) {
    if (e < qs || qe < s) return;
    if (qs <= s && e <= qe) {
    	cnt[node] += val;
    }
    else {
        int mid = (s+e)/2;
        update(2 * node, s, mid, qs, qe, val);
        update(2 * node + 1, mid + 1, e, qs, qe, val);
    }

    // 만약 자신이 해당범위에 들어와서 
    // 위에서 "cnt[now] += value" 로인해 1 이상이 되었다면

    // 자기 하위의 모든 노드들은 범위에 포함되므로, 
    // 끝 - 시작 + 1 이 cnt가 된다.
    if (cnt[node]) {
    	segTree[node] = yCom[e+1] - yCom[s];
    }
    else {
        // 겹치는 선분 넓이 0으로 처리
        if (s == e) segTree[node] = 0;
        // 아니면 갱신
        else segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int h = ceil(log2(MAX)+1);  // 2*MAX개
    int treeSize = 1 << (h + 1);
    cnt.resize(treeSize);
    segTree.resize(treeSize);
    
    cin >> N;
    for (int i=0; i<N; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> x2 >> y1 >> y2;
        v.push_back(T(x1,y1,y2,1));  // 시작 점
        v.push_back(T(x2,y1,y2,-1));  // 끝 점

        yCom.push_back(y1);
        yCom.push_back(y2);
    }

    sort(yCom.begin(), yCom.end());

    sort(v.begin(), v.end());  // x기준 정렬
    
    ll ans = 0;
    for (int i = 0; i < 2*N; i++) {
        if (i) ans += segTree[1] * (v[i].x - v[i - 1].x);

        // y1, y2 값 압축된 위치
        int qs = lower_bound(yCom.begin(), yCom.end(), v[i].y1) - yCom.begin();
        int qe = lower_bound(yCom.begin(), yCom.end(), v[i].y2) - yCom.begin();
        update(1, 0, 2*N, qs, qe-1, v[i].finish);
    }
    cout << ans;

    return 0;
}