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
https://www.acmicpc.net/problem/18437

회사 문화 5

Lazy Propagation + 오일러 투어 테크닉

*/

#define MAX 100'000

struct SegmentTree {

    using DataType = int;
    vector<DataType> tree;
    vector<DataType> lazy;  // 스위치가 바뀌었는가?

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
        lazy.resize(treeSize, -1);
    }

    // 미리 정해놓은 배열로 세그트리 구성
    DataType build(int node, int s, int e) {  // 인덱스 따라서 (1, 1, N) / (0, 0, N-1)
        if (s == e)
            return tree[node] = 1;
        int mid = (s + e) / 2;
        return tree[node] = build(node*2, s, mid) + build(node*2 + 1, mid + 1, e);
    }

    void update_lazy(int node, int s, int e) {
        if (lazy[node] == -1) return;
        tree[node] = (e-s+1)*lazy[node];
        if (s != e) lazy[node*2] = lazy[node*2+1] = lazy[node];
        lazy[node] = -1;
    }

    void update_range(int node, int s, int e, int left, int right, DataType value) {
        update_lazy(node, s, e);
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            tree[node] = (e-s+1) * value;
            if (s != e) {lazy[node*2] = lazy[node*2+1] = value;}
            return;
        }
        int mid = (s + e) / 2;
        update_range(node*2, s, mid, left, right, value);
        update_range(node*2 + 1, mid + 1, e, left, right, value);
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

    cin >> N;
    for (int i=1; i<=N; i++){
        int p;
        cin >> p;  // 직속 상사의 번호
        if (i==1) continue;
        adj[p].push_back(i);  // p의 직속 부하가 i
    }

    EulerTour(1);
    ST.build(1, 1, N);  // 회사의 모든 컴퓨터가 처음에 켜져있음!!!

    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;

        // i번직원의 부하들 컴퓨터 키기
        if (a==1){
            ST.update_range(1, 1, N, dfs_in[b]+1, dfs_out[b], 1);
        }
        // i번 직원 부하들 컴퓨터 끄기
        else if (a==2){
            ST.update_range(1, 1, N, dfs_in[b]+1, dfs_out[b], 0);
        }
        // i번 직원 부하들 컴퓨터 켜져있는 개수 출력
        else cout << ST.sum(1, 1, N, dfs_in[b]+1, dfs_out[b]) << "\n";
    }
}