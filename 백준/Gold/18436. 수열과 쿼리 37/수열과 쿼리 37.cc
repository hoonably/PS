#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'001

/*
2 l r : 짝수의 개수 출력 => r-l+1 - (홀수 개수)
3 l r : 홀수의 개수 출력
*/

int N, M;
ll arr[MAX];
vector<ll> segTree;

// 구간합 초기화
ll init(int node, int s, int e) {
    if (s == e)
        return segTree[node] = arr[s];
    int mid = (s + e) / 2;
    return segTree[node] = init(node*2, s, mid) 
    + init(node*2 + 1, mid + 1, e);
}

// idx 인덱스의 숫자를 diff만큼 변화
void update(int node, int s, int e, int idx, int diff){
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
    
    cin >> N;

    // 트리의 크기 (1~N일 경우)
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

    // arr[0]=0 으로 설정
    for (int i=1; i<=N; i++){
        int num;
        cin >> num;
        arr[i] = num%2;
    }

    // 기록되어있는 arr 이용해 트리 생성
    init(1, 1, N);

    cin >> M;

    for (int i=0; i<M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        // b번째 수를 c로 변경
        if (a==1){

            bool odd = c%2;  // 홀수인가?

            // 변화 없음
            if (arr[b]==odd) continue;

            if (!odd){
                arr[b]=odd;
                update(1, 1, N, b, -1);  // 홀수 -> 짝수
            }
            else {
                arr[b]=odd;
                update(1, 1, N, b, 1);  // 짝수 -> 홀수
            }
            
        }
        else if (a==2) {
            cout << c - b + 1 - sum(1, 1, N, b, c) << "\n";
        }
        else {
            cout << sum(1, 1, N, b, c) << "\n";
        }
    }
    
    return 0;
}