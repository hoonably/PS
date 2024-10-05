#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;\
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
반만 보고 판단

1. 문자열의 길이로 판단
2. 굳이 longlong으로 바꿀 필요 없이 string으로 비교
*/

#define MAX 

string n;
int ans;

string nums[10] = {"0","1","2","3","4","5","6","7","8","9"};

void check(string num){

    if (num.size() > n.size()) return;
    if (num.size() == n.size()){
        if (num <= n) ans++;
        return;
    }
    ans++;
}

void dfs(string num){
    string revNum = num;
    reverse(all(revNum));
    check(num+revNum);
    check(num+revNum.substr(1));  // 1번째부터 끝까지 문자열 자르기 (홀수)
    
    if (num.size()*2 >= n.size()) return;
    for(auto i : nums){
        dfs(num+i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    // 첫 숫자 0은 제외
    for(int i=1; i<=9; i++){
        dfs(nums[i]);
    }

    cout << ans;

    
    return 0;
}