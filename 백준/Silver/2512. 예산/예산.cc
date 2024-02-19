#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N;
    vector<int> want(N);
    for (int i=0; i<N; i++){
        cin >> want[i];
    }
    cin >> M;
    int start = 0;
    int end = *max_element(want.begin(), want.end());

    int ans = 0;
    while(start <= end){
        int mid = (start+end)/2;
        int sum = 0;
        for (int i=0; i<N; i++){
            sum += min(want[i], mid);
        }
        // 예산 안에 해결 가능
        if (sum <= M){
            start = mid+1;
            ans = mid;
        }
        else {
            end = mid-1;
        }
    }
    cout << ans;
    
    return 0;
}