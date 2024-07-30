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
세그먼트 트리로 버블소트할때 swap이 몇번 발생할지
swap의 개수 : 자신보다 작은 수의 개수

pair을 사용하여 second에 인덱스를 찾는다.
*/

#define MAX 500'000

pii arr[MAX+1];  // 미리 arr를 정해놓는 경우

struct SegmentTree {

    using DataType = int;
    vector<DataType> tree;

    SegmentTree(int size) {
        int h = ceil(log2(size+1));  // ceil : 정수로 올림
        int treeSize = 1 << (h + 1);
        tree.resize(treeSize);
    }

    // idx 인덱스의 숫자를 value "로" 변화
    void updateValue(int node, int s, int e, int idx, DataType value){
        if (idx > e || idx < s) return;
        if (s == e) {
            tree[node] = value; return;
        }
        int mid = (s + e) / 2;
        updateValue(node*2, s, mid, idx, value);
        updateValue(node*2 + 1, mid + 1, e, idx, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // left~right 구간합
    DataType sum(int node, int s, int e, int left, int right){
        if (left > e || right < s)
            return 0;
        if (left <= s && right >= e)
            return tree[node];
        int mid = (s + e) / 2;
        return sum(node*2, s, mid, left, right) 
        + sum(node*2 + 1, mid + 1, e, left, right);
    }
}ST(MAX);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    for (int i=1; i<=N; i++){
        int num;
        cin >> num;
        arr[i] = {num, i};
    }

    sort(arr+1, arr+N+1);

    // i > j이면서 arr[i] < arr[j]인 쌍의 개수
    ll ans = 0;
    for (int i=1; i<=N; i++){
        int idx = arr[i].second;
        // idx보다 큰 수의 개수 찾기
        ans += ST.sum(1, 1, N, idx+1, N);
        ST.updateValue(1, 1, N, idx, 1);
    }
    cout << ans;
    
    return 0;
}