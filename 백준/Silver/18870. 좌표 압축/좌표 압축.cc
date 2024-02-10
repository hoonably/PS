#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 두개의 벡터 사용
    vector<int> v, back;
    int N, X;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> X;
        v.push_back(X);
        back.push_back(X);
    }
    
    sort(v.begin(), v.end());

    // unique(v.begin(), v.end())
    // 중복인 것들을 뒤로 이동시킴
    // 뒤로 이동된 것 중에서 가장 앞 주소를 반환함.
    auto point = unique(v.begin(), v.end());

    // erase(시작, 끝) : 시작부터 끝까지 삭제
    v.erase(point, v.end());
    
    
    // lower_bound : 이진탐색기반으로 해당하는 값보다 크거나 같은값이 처음 등장하는 주소 반환 (정렬 전제)
    for(int i = 0; i < N; i++) {
        // lb = i번째 요소 값의 위치
        auto lb = lower_bound(v.begin(), v.end(), back[i]);
        cout << lb - v.begin() << ' ';
    }
    
}