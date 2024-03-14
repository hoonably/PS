#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    vector<int> arr(N);
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }

    int s = 0, e = N-1;
    int best = 2e9+1;
    int first;
    int last;

    while(s<e){
        int sum = arr[s]+arr[e];

        // 답 갱신
        if (abs(sum) < best){
            best = abs(sum);
            first = arr[s];
            last = arr[e];

            if (best==0) break;
        }


        if (sum<0) s++;
        else e--;
    }

    cout << first << ' ' << last;
    
    return 0;
}