#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 200'000
#define MOD 1'000'000'007

/*
V자 모양의 쌍의 개수

y좌표를 오름차순으로, y좌표가 같다면 x좌표를 오름차순으로 정렬


같은 y좌표끼리는 V자형 별자리를 만들 수 없으므로 update로 제거

왼쪽부터 훑으면서 y좌표가 큰 별이 몇개인지 세고
오른쪽부터 훑으면서 y좌표가 큰 별이 몇개인지 센 후에 곱하기

x좌표가 음수부터 있기 때문에 인덱스 처리를 잘 해주자.
-200000 ~ 200000 이므로 20만을 더해주자.
*/

int N;
vector<int> segTree;
vector<pair<pii, int>> arr, rarr;

// idx 인덱스를 추가
void update(int node, int s, int e, int idx){
    if (idx > e || idx < s) return;
    segTree[node] ++;
    if (s == e) return;
    int m = (s + e) / 2;
    update(node*2, s, m, idx);
    update(node*2 + 1, m + 1, e, idx);
}

// left~right 구간합
int sum(int node, int s, int e, int left, int right){
    if (left > e || right < s) return 0;
    if (left <= s && right >= e) return segTree[node];
    int m = (s + e) / 2;
    return sum(node*2, s, m, left, right) 
    + sum(node*2+1, m+1, e, left, right);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    int h = ceil(log2(MAX*2));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

    // x, y 좌표와 그 인덱스 기록
    for (int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({{x, y}, i});
        rarr.push_back({{-x, y}, i});
    }

    sort(arr.begin(), arr.end());
    sort(rarr.begin(), rarr.end());

    vector<ll> cnt(N);

    // 자신보다 왼쪽에 있는 것 중에서 y값이 더 큰 값 구하기
    for (auto i : arr) {
        int y = i.first.second + MAX;  // 음수 인덱스 방지 + MAX
        int idx = i.second;
        cnt[idx] = sum(1, 0, 2*MAX, y+1, 2*MAX);
        update(1, 0, 2*MAX, y);  // x가 증가하면서 y값 update
    }

    // 트리 초기화
    segTree = vector<int>(treeSize);

    // 자신보다 오른 쪽에 있는 것 중에서 y값이 더 큰 값 구하기
    ll ans = 0;
    for (auto i : rarr) {
        int y = i.first.second + MAX;
        int idx = i.second;
        // 기존에 기록했던 왼쪽합과 곱해줌
        cnt[idx] *= sum(1, 0, 2*MAX, y+1, 2*MAX);
        ans = (ans+cnt[idx]) % MOD;
        update(1, 0, 2*MAX, y);  // x가 감소하면서 y값 update
    }
    cout << ans << '\n';
    
    return 0;
}