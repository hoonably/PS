#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100'000

/*
이번엔 최소값인 인덱스를 출력하는 문제]
first : 값, second : 인덱스

min 사용시 pair 자동 정렬로 인해 first가 같다면 second값이 작은 것으로 return 된다.
*/

pii arr[MAX];
vector<pii> segTree;

// 최대값 트리 초기화
pii init(int node, int s, int e) {
    if (s == e)
        return segTree[node] = arr[s];
    int mid = (s + e) / 2;
    auto l = init(node*2, s, mid);
    auto r = init(node*2 + 1, mid + 1, e);
    return segTree[node] = min(l, r);
}

// idx 인덱스의 숫자를 value로 변화
void update(int node, int s, int e, int idx, pii value){
    if (idx < s || e < idx) return;
    if (s == e){
        segTree[node] = value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);
    segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);
}

// left ~ right 구간에서 최대값을 반환
pii getMin(int node, int s, int e, int left, int right){
    if (left > e || right < s)
        return {1e9, 1e9};  // 답에 영향을 받지 않는 값으로
    if (left <= s && right >= e)
        return segTree[node];
    int mid = (s + e) / 2;
    auto l = getMin(node*2, s, mid, left, right);
    auto r = getMin(node*2 + 1, mid + 1, e, left, right);
    return  min(l, r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    // 트리의 크기 (1~N일 경우)
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

    for (int i=1; i<=N; i++){
        int val;
        cin >> val;
        arr[i] = {val, i};
    }

    // 기록되어있는 arr 이용해 트리 생성
    init(1, 1, N);
    
    int M;
    cin >> M;
    for (int i=0; i<M; i++){
        int a,b,c;
        cin >> a;
        if (a==1){
            cin >> b >> c;
            update(1,1,N,b,{c,b});
        }
        else {
            cout << segTree[1].second << '\n';
        }
    }
    
    return 0;
}