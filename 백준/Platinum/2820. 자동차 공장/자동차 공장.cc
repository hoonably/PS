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
https://www.acmicpc.net/problem/2820

자동차 공장

Lazy Propagation + 오일러 투어 테크닉

미리 정해놓은 배열로 세그트리 구성할때
ar[s]로 그대로 넣지 말고, 순서가 바뀌므로
arr[dfs_in[i]] = ar[i]; 을 사용해
그래프 기준으로 배열을 바꿔주고 넣는다.
*/

#define MAX 500'000

int ar[MAX+1];  // 사람 기준
int arr[MAX+1];  // 그래프 기준

int N, M;
vector<int> adj[MAX+1];
int dfs_in[MAX+1];  // i번 정점에 방문한 시점 기록
int dfs_out[MAX+1];  // i번 정점을 빠져나온 시점 기록
int idx = 0;

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

    // 미리 정해놓은 배열로 세그트리 구성
    // 여기서 build를 사용하면
    // 그냥 arr[s]로 넣어주면 나중에 정렬되어 트리에 넣기 때문에 인덱스가 달라짐
    // ex) 1 -> 3 -> 5 -> 4 -> 2 이런식으로 트리에 들어갈 수 있음
    DataType build(int node, int s, int e) {  // 인덱스 따라서 (1, 1, N) / (0, 0, N-1)
        if (s == e)
            return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = build(node*2, s, mid) + build(node*2 + 1, mid + 1, e);
    }

    void update_lazy(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node]*(e-s+1);
            if (s != e) lazy[node*2] += lazy[node], lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update_range(int node, int s, int e, int left, int right, DataType diff) {
        update_lazy(node, s, e);  // 기존에 lazy 값이 있음
        if (left > e || right < s) return;
        if (left <= s && e <= right) {
            tree[node] += diff * (e-s+1);
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

    cin >> N >> M;
    for (int i=1; i<=N; i++){
        cin >> ar[i];
        if (i==1) continue;
        int p;
        cin >> p;  // 직속 상사의 번호
        adj[p].push_back(i);  // p의 직속 부하가 i
    }

    EulerTour(1);

    // ar  : 사람 이름 기준
    // arr : 정렬된 그래프 기준
    for (int i = 1; i <= N; i++) arr[dfs_in[i]] = ar[i];
    ST.build(1, 1, N);  // 틀림

    while(M--){
        char q; int a, x;
        cin >> q;
        if (q=='p'){
            cin >> a >> x;  // a의 부하들 월급 x 증가
            ST.update_range(1, 1, N, dfs_in[a]+1, dfs_out[a], x);
        }
        else {
            cin >> a;  // a의 월급
            cout << ST.sum(1, 1, N, dfs_in[a], dfs_in[a]) << "\n";
        }
    }
}