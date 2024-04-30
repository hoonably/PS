#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX

/*

*/

int N, M;
vector<string> str;
int dp[1000];  // 그 이전까지의 누적 합

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    
    str.resize(N);

    for (int i=0; i<N; i++){
        cin >> str[i];
    }

    // 사전순 : ACGT

    string ans = "";
    int ans2 = M*N;

    // 각 자리수에서 가장 많이 나오는 것으로
    for (int i=0; i<M; i++){
        map<char,int> cnt = {{'A',0},{'C',0},{'G',0},{'T',0}};
        for (string s : str){
            cnt[s[i]]++;
        }

        pair<char, int> best = {'A',0};
        for (pair<char, int> c : cnt){
            if(c.second > best.second) swap(best,c);
        }

        ans += best.first;
        ans2 -= best.second;  // 맞은 횟수만큼 빼줌
    }

    cout << ans << '\n' << ans2;
    
    return 0;
}