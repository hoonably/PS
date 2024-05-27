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
https://www.acmicpc.net/problem/17615
공을 옮겨서 
RRRRRBBBBB
혹은
BBBBBRRRRR 처럼 같은 색끼리 나오게 만드려면 최소 몇번 옮겨야 하는가?
swap개념이 아니라 그냥 옮기는거
*/

#define MAX 

int N;
string str;

int group(char x){
    // 왼쪽에 공을 몰아넣기
    int cnt1 = 0;
    bool ch = false;
    for(int i=0; i<str.size(); i++){
        if(str[i]!=x) ch = true;
        else if(ch&&str[i]==x) cnt1++;
    }
    ch = false;

    // 오른쪽에 공을 몰아넣기
    int cnt2 = 0;
    for(int i=str.size()-1; i>=0; i--){
        if(str[i]!=x) ch = true;
        else if(ch&&str[i]==x) cnt2++;
    }
    return min(cnt1, cnt2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    cin >> str;

    cout << min(group('R'), group('B'));
    
    return 0;
}