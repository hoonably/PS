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

*/

#define MAX 

int N;
int sum, cnt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        int h;
        cin >> h;
        sum += h;
        cnt += h/2;
    }

    if (sum%3) cout << "NO";
    else if (cnt >= sum/3) cout << "YES";
    // sum/3 : 물뿌리개 사용 횟수

    // 2만큼 성장하는 물뿌리개 사용 횟수 = 전체 걸리는 날 : 3의 배수므로 1도 2와 같은 횟수 사용했으니 무조건 충족
    // 2만큼 성장하는 물뿌리개 사용 횟수 > 전체 걸리는 날 : 2 중에 몇은 1을 2번 사용하여 만들 수 있고 3의 배수이므로 충족

    else cout << "NO"; 



    
    return 0;
}