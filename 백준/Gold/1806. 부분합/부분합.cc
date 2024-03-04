#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, S;
    cin >> N >> S;
    vector<int> sum(N+1);

    for (int i=1; i<=N; i++){
        int num;
        cin >> num;
        sum[i] = sum[i-1] + num;
    }

    int s=1, e=1;

    int ans = 1e9;

    while(e<=N){
        int temp = sum[e]-sum[s-1];  // 부분합으로 구하기

        // 조건 만족
        if (temp>=S){
            ans = min(ans, e-s+1);
            if (ans==1) break;
            s++;
        }

        else {
            e++;
        }
    }

    if (ans==1e9) cout << 0;
    else cout << ans;
    
    return 0;
}