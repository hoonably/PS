#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
어떻게 풀어야 할지 막막했는데,
연속된 수여야 하고, 중복되는 수는 없기 때문에,
최대값, 최소값을 사용하면 된다.

6개인데 최소값 : 3 최대값 : 8 이라면 3~8이 모두 있는 것이다.
*/

#define MAX 100'000

int arr[MAX+1];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = pair<int,int>;
    vector<DataType> tree;

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
    }

    // 미리 정해놓은 배열로 세그트리 구성
    DataType build(int node, int s, int e) {  // 인덱스 따라서 (1, 1, N) / (0, 0, N-1)
        if (s == e)
            return tree[node] = {arr[s], arr[s]};
        int mid = (s + e) / 2;
        DataType l = build(node*2, s, mid);
        DataType r = build(node*2 + 1, mid + 1, e);
        return tree[node] = {min(l.first,r.first), max(l.second, r.second)};
    }

    DataType update(int node, int s, int e, int idx, int value) {
        if (idx < s || idx > e) return tree[node];
        if (s == e) return tree[node] = {value, value};
        int mid = (s + e) >> 1;
        DataType l = update(2 * node, s, mid, idx, value);
        DataType r = update(2 * node + 1, mid + 1, e, idx, value);
        return tree[node] = {min(l.first, r.first), max(l.second, r.second)};
    }

    // left ~ right 구간에서 최소값, 최대값을 pair로 반환
    DataType getMinMax(int node, int s, int e, int left, int right){
        if (left > e || right < s)
            return {INF, 0};  // 답에 영향을 받지 않는 값으로
        if (left <= s && right >= e)
            return tree[node];
        int mid = (s + e) / 2;
        DataType l = getMinMax(node*2, s, mid, left, right);
        DataType r = getMinMax(node*2 + 1, mid + 1, e, left, right);
        return {min(l.first, r.first), max(l.second, r.second)};
    }

}ST(MAX);

void solve(){
    int N, K;
    cin >> N >> K;

    // 현재 위치를 반환해주는 배열 초기화
    for (int i = 0; i < N; i++) arr[i] = i;

    // 트리 생성
    ST.build(1, 0, N-1);

    for (int i=0; i<K; i++){
        int Q, A, B;
        cin >> Q >> A >> B;
        if (Q==0){  // A와 B 바꾸기
            ST.update(1, 0, N-1, arr[A], B);  // A의 위치에 B를 넣기
            ST.update(1, 0, N-1, arr[B], A);  // B의 위치에 A를 넣기
            swap(arr[A], arr[B]);  // A, B 위치 업데이트
        }
        else {  // A~B 선반에 있는 DVD가 A~B인가? (순서 상관 X)
            // 최소값이 A, 최대값이 B가 나와야함
            auto [mini, maxi] = ST.getMinMax(1, 0, N-1, A, B);
            if (mini==A && maxi==B) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}