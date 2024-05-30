#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/4889

*/

#define MAX 



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T = 1;
    while(true){
        string str;
        cin >> str;
        if (str[0]=='-') break;

        // 틀린 문자열 개수
        int ans = 0;

        // 짝을 못찾은 { 의 개수
        int cnt = 0;
        for (char c: str){
            if(c=='{'){
                cnt++;
            }
            else {
                if (cnt>0) cnt--;
                else {
                    ans++;
                    cnt++;
                }
            }
        }

        cout << T << ". " << ans + cnt / 2 << '\n';
        T++;
    }
    
    return 0;
}