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
세그먼트 트리
최솟값과 최댓값 구하기
pair 이용 first : 최소값, second : 최대값
*/

#define MAX 100'000

ll arr[MAX+1];  // 미리 arr를 정해놓는 경우

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

int N, M;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    // arr[0]=0 으로 설정
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 트리 생성
    ST.build(1, 1, N);

    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // a번째수 ~ b번째 수 합 구하기
        auto temp = ST.getMinMax(1, 1, N, a, b);
        cout << temp.first << ' ' << temp.second << "\n";
    }
    
    return 0;
}