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

Manacher's Algorithm
문자열의 부분 문자열이 팰린드롬인지 O(n)에 판단하는 manacher 알고리즘

문자열 S에 대한 배열 A를 구할 수 있다.

A[i] : i번째 문자를 중심으로 하는 가장 긴 회문의 반지름 크기를 의미한다.

ex) bananac에서 A[4]는 b<anana>c 최대 반지름인 2가 된다.

어떤 문자열 S에서 A[i]가 존재한다면, 
i - A[i]에서 i + A[i]까지는 팰린드롬이고, 
i - A[i] - 1에서 i + A[i] + 1까지는 팰린드롬이  아니다.

이 과정을 이용하여 bananac라는 문자열에 대한 배열 A를 알아보자.


*/

#define MAX 100'000

int A[2*MAX+2];
 
void manachers(string S, int len){
    int r = 0, p = 0;
    for (int i = 0; i < len; i++){
        if (i <= r) A[i] = min(A[2 * p - i], r - i);
        else A[i] = 0;
 
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < len && S[i - A[i] - 1] == S[i + A[i] + 1])
            A[i]++;
 
        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}

string str, temp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> str;
 
    int len = str.size();
 
    for (int i = 0; i < len; i++){
        temp += '#';
        temp += str[i];
    }
    temp += '#';
    
    len = 2*len+1;
    manachers(temp, len);

    int ans = 0;
    for (int i = 0; i < len; i++)
        ans = max(ans, A[i]);
 
    cout << ans;
    
    return 0;
}