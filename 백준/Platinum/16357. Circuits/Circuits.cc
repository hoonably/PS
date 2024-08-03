#include <bits/stdc++.h>
#define all(v) v.begin(), v.e()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/16357

Circuits (전기 회로)

Sweeping + Lazy Propagation Segment tree

가로 선 두개를 그어 최대한 많은 회로를 연결해야함
(x좌표는 쓸모없음)

어려워서 풀이 참고함

여기서 Lazy Propagation의 쿼리는 구간합이 아닌 구간 최댓값을 구하도록 해주어야 한다.
점들을 정렬하고 스위핑을 하는데 기준이 되는 두 점을 정해야 하므로 매 순간 한 점을 지정한다고 하자.
그렇다면 해당 점의 y좌표와 만나는 모든 사각형을 제외한 나머지 중 모든 y값에 대해 최댓값이 되는 점을
Lazy Propagation으로 쿼리를 이용해 처리하면 된다.

근데 문제가 있다. 만약 큰 사각형이 작은 사각형을 아예 감싼다고 하자.
그리고 위의 두 사각형을 지나는 선과 겹치지 않는 다른 영역에 대해 선이 지나가야 최댓값이 나온다고 하자.
그럼 큰 사각형의 시작선을 만나고 바로 [시작, 끝]에 대해 -1을 업데이트하고 쿼리로 값을 가져온다면
나중에 작은 사각형을 없앨 차례가 왔을 때 직전에 처리한 큰 사각형의 정보를 잃어버리게 된다.
*/

#define MAX 200'000

pii arr[MAX+1];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = int;
    vector<DataType> tree;
    vector<DataType> lazy;

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
        lazy.resize(treeSize);
    }

    void update_lazy(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (s != e) lazy[node*2] += lazy[node], lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update_range(int node, int s, int e, int left, int right, DataType diff) {
        update_lazy(node, s, e);
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            tree[node] += diff;
            if (s != e) {lazy[node*2] += diff; lazy[node*2+1] += diff;}
            return;
        }
        int mid = (s + e) / 2;
        update_range(node*2, s, mid, left, right, diff);
        update_range(node*2 + 1, mid + 1, e, left, right, diff);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    // left~right 최대값
    DataType find(int node, int s, int e, int left, int right){
        update_lazy(node, s, e);
        if (left > e || right < s) return 0;
        if (left <= s && right >= e) return tree[node];
        int mid = (s + e) / 2;
        return find(node*2, s, mid, left, right)
        + find(node*2 + 1, mid + 1, e, left, right);
    }

}ST(MAX);

int n;

void compression(){  // 좌표 압축
    vector<int> vec;
    for(int i=1; i<=n; i++) vec.push_back(arr[i].first), vec.push_back(arr[i].second);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());  // 중복 제거
    for(int i=1; i<=n; i++) arr[i].first = lower_bound(vec.begin(), vec.end(), arr[i].first) - vec.begin()+1;
    for(int i=1; i<=n; i++) arr[i].second = lower_bound(vec.begin(), vec.end(), arr[i].second) - vec.begin()+1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        int _;
        cin >> _ >> arr[i].second >> _ >> arr[i].first;
    }
    compression();
    sort(arr+1, arr+n+1);

    for (int i=1; i<=n; i++){
        ST.update_range(1, 1, MAX, arr[i].first, arr[i].second, 1);
    }

    vector<int> tVec(MAX+1);
    for (int i=1; i<=MAX; i++) tVec[i] = ST.find(1, 1, MAX, i, i);

    int ans = 0;
	int cnt = 0;
    for(int i=1; i<=MAX; i++){
        while(cnt <= n && arr[cnt].first <= i){
            ST.update_range(1, 1, MAX, arr[cnt].first, arr[cnt].second, -1);
            cnt++;
        }
		ans = max(ans, tVec[i] + ST.find(1, 1, MAX, 1, MAX));
	}
    cout << ans;
}