#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
binary_search를 통해 어레이가 아닌 상수값을 찾는다.
하나가 아니기 때문에 가능한 경우에도 
low값을 하나씩 올려가면서 최대인 값을 계속 탐색한다.
*/

int K, N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> K >> N;
    vector<unsigned int> lan(K);
    for (int i=0; i<K; i++){
        cin >> lan[i];
    }
    unsigned int maximum = *max_element(lan.begin(), lan.end());

    unsigned int low = 1, high = maximum, ans = 0;

    while(low <= high){
        unsigned int mid = (low + high)/2;

        unsigned int cnt = 0;  // 자른 랜선 개수 초기화
        for (int i=0; i<K; i++){
            cnt += lan[i] / mid;
        }

        // 랜선개수가 맞거나 더 크면
        if (cnt >= N){
            low = mid + 1;
            ans = max(ans, mid);
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
    
    return 0;
}