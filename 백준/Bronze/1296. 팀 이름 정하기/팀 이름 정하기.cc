#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

int yl, yo, yv, ye;
int ans = -1;
string ans_str;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string yeondu;
    cin >> yeondu;
    for(char c : yeondu){
        if(c == 'L') yl++;
        else if(c == 'O') yo++;
        else if(c == 'V') yv++;
        else if(c == 'E') ye++;
    }

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        int l=yl, o=yo, v=yv, e=ye;
        for(char c : s){
            if(c == 'L') l++;
            else if(c == 'O') o++;
            else if(c == 'V') v++;
            else if(c == 'E') e++;
        }
        int score = ((l+o)*(l+v)*(l+e)*(o+v)*(o+e)*(v+e))%100;
        if(score > ans){
            ans = score;
            ans_str = s;
        }
        else if(score == ans){
            if(s < ans_str) ans_str = s;
        }
    }
    cout << ans_str << '\n';
    
    return 0;
}