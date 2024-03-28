#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    
    int ans = 0;

    // 불가능한 경우
    if (n==1 || n==3) ans = -1;

    // 짝수인 경우
    else if (n%2==0){
        ans = (n / 10) * 2;
        ans += (n%10)/2;
    }
    // 홀수인데 5, 7, 9 인 경우
    else if (n%10 >=5){
        ans = n/5;
        ans += (n%5)/2;
    }
    // 홀수인데 1, 3인 경우
    // 4원을 빼주고 푼 후에 2 추가
    else {
        n -= 4;
        ans = n/5 + 2;
        ans += (n%5)/2;
    }

    cout << ans;
    
    return 0;
}