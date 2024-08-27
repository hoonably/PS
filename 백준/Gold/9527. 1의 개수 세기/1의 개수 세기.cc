#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/9527

생각해내기어려웠던 문제
https://murphy55.tistory.com/entry/boj9527
*/

#define MAX 

ll Log2(ll n) {
    for(int i = 63; i >= 0; i--) {
        if(n & (1LL << i)) return i;
    }

    return 0;
}

// 0~n까지 이진수로 표현했을때 1의 개수의 합
ll go(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    ll logn = Log2(n);

    // 이용한 방식
    // 0~7의 1의 개수가 8~15의 0의 개수가 일치한다!
    // => 직사각형의 넓이를 이용

    // ex) 0~19 구간을 구한다고 했을 때

    //up :0~15 구간의 직사각형의 넓이
    ll up = (1LL << (logn-1)) * logn;
    // left : 16~19 구간의 최상위 비트 개수
    ll left = n - ((1LL << logn)-1);
    // right : 16~19 구간에서 재귀로 작은 구간의 1의 개수
    ll right = go(left-1);

    return up+left+right;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll a, b;

    cin >> a >> b;

    // a~b 구간 합
    cout << go(b) - go(a-1);
    
    return 0;
}