#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'001

/*
세그먼트 트리
최솟값과 최댓값 구하기
pair 이용 first : 최소값, second : 최대값
*/

int N, M;
ll arr[MAX];
vector<pair<ll,ll>> segTree;

pair<ll,ll> init(int node, int start, int end) {
    if (start == end)
        return segTree[node] = {arr[start], arr[start]};
    int mid = (start + end) / 2;
    auto l = init(node*2, start, mid);
    auto r = init(node*2 + 1, mid + 1, end);
    return segTree[node] = {min(l.first,r.first), max(l.second, r.second)};
}

// void update(int node, int start, int end, int idx, ll value){
//     if (idx < start || end < idx) return;
//     if (start == end){
//         segTree[node] = {value,value};
//         return;
//     }
//     int mid = (start + end) / 2;
//     update(node * 2, start, mid, idx, value);
//     update(node * 2 + 1, mid + 1, end, idx, value);
//     segTree[node].first = min(l.first, r.first);
//     segTree[node].second = max(l.second, r.second);
// }

pair<ll,ll> getMinMax(int node, int start, int end, int left, int right){
    if (left > end || right < start)
        return {1e9,0};  // 답에 영향을 받지 않는 값으로
    if (left <= start && right >= end)
        return segTree[node];
    int mid = (start + end) / 2;
    auto l = getMinMax(node*2, start, mid, left, right);
    auto r = getMinMax(node*2 + 1, mid + 1, end, left, right);
    return {min(l.first, r.first), max(l.second, r.second)};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

    // arr[0]=0 으로 설정
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 트리 생성
    init(1, 1, N);

    for (int i=0; i<M; i++){
        ll a, b;
        cin >> a >> b;
        // a번째수 ~ b번째 수 합 구하기
        auto temp = getMinMax(1, 1, N, a, b);
        cout << temp.first << ' ' << temp.second << "\n";
    }
    
    return 0;
}