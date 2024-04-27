#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
1. 어떤 문자를 K개 포함하는 가장 짧은 문자열의 길이 구하기
2. 어떤 문자를 K개 포함하는 가장 긴 문자열의 길이 구하기 (양 끝은 K)

슬라이딩 윈도우
=> 투 포인터 사용
*/

void solve(){
    string W;
    int K;
    cin >> W;
    cin >> K;

    vector<int> count(26);  // 문자열 별로 등장 빈도수 기록
    for (char c : W) count[c-'a']++;

    int mini = 1e9;
    int maxi = -1;

    for (int i = 0; i < W.length(); ++i) {
        // ⭐ 빈도수가 K 개 미만인 문자들은 문자열도 못 만들므로 패스
        if (count[W[i] - 'a'] < K)
            continue;

        int cnt = 0;
        for (int j = i; j < W.length(); ++j) {  // 연속 문자열의 시작 문자 W[i]
            if (W[i] == W[j])
                cnt++;
            
            if (cnt == K) {  // 카운트 수가 K 와 같을 때 길이 업데이트
                mini = min(mini, j - i + 1);
                maxi = max(maxi, j - i + 1);
                break;
            }
        }
    }
    
    if (maxi == -1) cout << "-1\n";
    else cout << mini << ' ' << maxi << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}