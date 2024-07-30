#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'001

/*
세그먼트 트리
N=8 -> 트리에서 8~15는 arr[0]~[7]

편의를 위해 arr[0]=0 으로 지정
*/

int N, M, K;
ll arr[MAX];
ll segTree[MAX*4];

// 구간합 초기화
ll init(int node, int s, int e) {
    if (s == e)
        return segTree[node] = arr[s];
    int mid = (s + e) / 2;
    return segTree[node] = init(node*2, s, mid) 
    + init(node*2 + 1, mid + 1, e);
}

// idx 인덱스의 숫자를 diff만큼 변화
void update(int node, int s, int e, int idx, ll diff){
    if (idx > e || idx < s) return;
    segTree[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(node*2, s, mid, idx, diff);
    update(node*2 + 1, mid + 1, e, idx, diff);
}

// left~right 구간합
ll sum(int node, int s, int e, int left, int right){
    if (left > e || right < s)
        return 0;
    if (left <= s && right >= e)
        return segTree[node];
    int mid = (s + e) / 2;
    return sum(node*2, s, mid, left, right) 
    + sum(node*2 + 1, mid + 1, e, left, right);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    // arr[0]=0 으로 설정
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 트리 생성
    init(1, 1, N);

    for (int i=0; i<M+K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        // b번째 수를 c로 변경
        if (a==1){
            ll diff = c - arr[b];  // 새로운 수 - 기존 수
            arr[b] = c;
            update(1, 1, N, b, diff); 
        }
        // b번째수 ~ C번째 수 합 구하기
        else {
            cout << sum(1, 1, N, b, c) << "\n";
        }
    }
    
    return 0;
}