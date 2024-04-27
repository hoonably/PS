#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
1. 어떤 문자를 K개 포함하는 가장 짧은 문자열의 길이 구하기
2. 어떤 문자를 K개 포함하는 가장 긴 문자열의 길이 구하기 (양 끝은 K)


*/

void solve(){
    string W;
    int K;
    cin >> W;
    cin >> K;

    // 각 문자가 나오는 위치 저장
    vector<int> v[26];
    for (int i = 0; i < W.size(); i++) {
        v[W[i] - 'a'].push_back(i);
    }

    int mini = 1e9;
    int maxi = -1;

    // 각 문자별로 진행
    // 나온 시작 지점과 K번째 후 지점
    for (int i = 0; i < 26; i++){
        if (v[i].size() >= K){
            for (int j = 0; j <= v[i].size() - K; j++){
                mini = min(mini, v[i][j + K - 1] - v[i][j] + 1);
                maxi = max(maxi, v[i][j + K - 1] - v[i][j] + 1);
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