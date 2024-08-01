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
https://www.acmicpc.net/problem/14268

Lazy Propagation + 오일러 투어 테크닉

Array와 달리 Graph는 연속성이 정해져 있지 않다. 
즉, 그래프의 형태에 따라 업데이트 하고자 하는 구간이 연속적일수도 있고, 아닐 수도 있다. 
따라서 우리는 일반 그래프의 형태가 아닌 Tree에서의 쿼리 처리를 먼저 고민해보아야 한다.

dfs를 통해 정점의 번호를 지정 : 한 분기 내의 정점들이 연속된 번호를 부여받을 수 있도록 하는 작업
각 정점들이 "자식 노드의 번호의 범위(구간)"을 저장한다
즉, 정점 u에 대해 [u의 번호, max(v의 번호)] (v는 u의 자손 정점)와 같은 형태의 구간을 저장하도록 하는 것이다.
*/

#define MAX 100'000

// ll arr[MAX+1];  // 미리 arr를 정해놓는 경우

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
            tree[node] += (e-s+1)*lazy[node];
            if (s != e) lazy[node*2] += lazy[node], lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update_range(int node, int s, int e, int left, int right, DataType diff) {
        update_lazy(node, s, e);  // 기존에 lazy 값이 있음
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            tree[node] += (e-s+1) * diff;
            if (s != e) {lazy[node*2] += diff; lazy[node*2+1] += diff;}
            return;
        }
        int mid = (s + e) / 2;
        update_range(node*2, s, mid, left, right, diff);
        update_range(node*2 + 1, mid + 1, e, left, right, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    // left~right 구간합 출력
    DataType sum(int node, int s, int e, int left, int right){
        update_lazy(node, s, e);
        if (left > e || right < s) return 0;
        if (left <= s && right >= e) return tree[node];
        int mid = (s + e) / 2;
        return sum(node*2, s, mid, left, right)
        + sum(node*2 + 1, mid + 1, e, left, right);
    }

}ST(MAX);

int N, M;
vector<int> adj[MAX+1];
int dfs_in[MAX+1];  // i번 정점에 방문한 시점 기록
int dfs_out[MAX+1];  // i번 정점을 빠져나온 시점 기록
int idx = 0;

// 이 문제는 직속상사라 par 필요 없음
void EulerTour(int now){  // (int now, int par){
    dfs_in[now] = ++idx;
    for(auto next : adj[now]){
        // if(next==par) continue;
        EulerTour(next);  // EulerTour(next, now);
    }
    dfs_out[now] = idx;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dfs_out, -1, sizeof(dfs_out));

    cin >> N >> M;
    for (int i=1; i<=N; i++){
        int p;
        cin >> p;  // 직속 상사의 번호
        if (i==1) continue;
        adj[p].push_back(i);  // p의 직속 부하가 i
    }

    EulerTour(1);

    while(M--){
        int a, b, c;
        cin >> a;
        if (a==1){
            cin >> b >> c;  // b가 직속 부하에게 c만큼 칭찬 받음
            ST.update_range(1, 1, N, dfs_in[b], dfs_in[b], c);
        }
        else {
            cin >> b;  // b가 받은 칭찬의 정도
            // i를 루트로 하는 서브트리에 있는 노드들이 받은 갈굼의 합
            cout << ST.sum(1, 1, N, dfs_in[b], dfs_out[b]) << "\n";
        }
    }
}