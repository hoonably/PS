#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
1. 전체 물건을 두 그룹으로 나눈 뒤,
 각 그룹에서 가능한 모든 조합을 탐색하여 기록해둔다.

2. A그룹에서 무게 w를 만들 수 있다면, 
B그룹에서 무게 C-w 이하를 만들 수 있어야 한다.

3. A그룹에서 만들 수 있는 모든 무게에 대해, 
이분탐색을 이용하여 B그룹에서 C-w이하를 만드는 조합의 수를 구한다.
*/

int N, C;
vector<int> items(30);
vector<int> lCombi, rCombi;


// item을 넣었을 경우와 넣지 않았을 경우로 계속 재귀하여 C 이하의 모든 무게 합 기록
void makeCombi(int idx, int end, int weight, vector<int>& v) {
    if (weight > C) return;
    if (idx == end) {
        v.push_back(weight);
        return;
    }

    makeCombi(idx+1, end, weight+items[idx], v);
    makeCombi(idx+1, end, weight, v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> N >> C;
    for (int i=0; i<N; i++) cin >> items[i];

    // 각각 반으로 나누어 C 이하의 무게합을 경우의 수로 생성
    makeCombi(0, N/2, 0, lCombi);
    makeCombi(N/2, N, 0, rCombi);
    
    // 이분탐색을 위한 우측 정렬
    sort(rCombi.begin(), rCombi.end());
    

    // 좌측 경우의 수를 weight라고하면,
    // 우측에서 C-weight 이하가 나오면 됨 
    // -> 정렬되어있으므로 C-weight의 index가 추가되는 경우의 수
    ll ans = 0;
    for (auto weight: lCombi) {
        ans += upper_bound(rCombi.begin(), rCombi.end(), C-weight) - rCombi.begin();
    }
    
    cout << ans;

    return 0;
}