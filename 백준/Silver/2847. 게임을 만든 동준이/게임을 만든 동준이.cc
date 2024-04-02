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
    
    int N;
    int score[101];
    cin >> N;
    
    int ans = 0;

    for (int i=0; i<N; i++){
        cin >> score[i];
    }

    for (int i=N-2; i>=0; i--){
        if (score[i] < score[i+1]) continue;

        int temp = score[i+1]-1;
        ans += score[i] - temp;
        score[i] = temp;
    }

    cout << ans;
    
    return 0;
}