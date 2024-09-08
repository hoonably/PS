#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
역방향 이동하는 거리 * 2만 더해주면 된다.
역방향일 때만 넣어줌
*/

int N, M;
vector<pii> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<N; i++){
        int s, e;
        cin >> s >> e;
        if (s>e) v.push_back({e,s});
    }

    if (v.empty()){  // 모두 순방향
        cout << M;
        return 0;
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    int left = v[0].first;
    int right = v[0].second;

    for (int i=1; i<v.size(); i++){

        // 가장 오른쪽에 있는 것보다 왼쪽에 시작한다면
        // 기존 선분이랑 이을 수 있음
        if (v[i].first <= right) {
            right = max(right, v[i].second);
        }

        // 가장 오른쪽에 있던 것보다 더 오른쪽에서 시작한다면
        // 떨어져있는 선분 생성하니 기존 선분 답에 추가
        else {
            ans += right - left;
            left = v[i].first;
            right = v[i].second;
        }
    }
    ans += right - left;

    cout << 2*ans + M;

    return 0;
}