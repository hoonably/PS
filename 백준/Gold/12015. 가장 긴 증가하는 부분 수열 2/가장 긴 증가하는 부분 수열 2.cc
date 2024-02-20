#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
새로운 정답 배열을 만들고,
이분탐색을 이용해 
*/

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    vector<int> B;
    B.push_back(A[0]); 

    int ans = 1;
    for (int i=1; i<N; i++){
        // B의 마지막 값보다 크다면 B에 push
        if (A[i] > B.back()){
            B.push_back(A[i]);
            ans++;
        }
        // 아니라면 들어갈 자리 탐색
        else{
            int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            B[idx] = A[i];
        }
    }

    cout << ans;  // ans = B.size()
    
    return 0;
}