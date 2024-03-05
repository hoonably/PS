#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    int best_p = 1e9;
    int best_n = 1e9;
    for (int i=0; i<M; i++){
        int p, n;
        cin >> p >> n;
        best_p = min(best_p, p);
        best_n = min(best_n, n);
    }

    // 낱개로 사는게 더 좋은 경우
    cout << min({N*best_n, (N/6)*best_p + (N%6)*best_n, (N/6+1)*best_p});


    return 0;
}