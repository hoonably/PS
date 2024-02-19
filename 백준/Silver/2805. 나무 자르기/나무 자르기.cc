#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
binary_search를 통해 어레이가 아닌 상수값을 찾는다.
하나가 아니기 때문에 가능한 경우에도 
low값을 하나씩 올려가면서 최대인 값을 계속 탐색한다.
*/

int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    vector<int> tree(N);
    for (int i=0; i<N; i++){
        cin >> tree[i];
    }
    int maximum = *max_element(tree.begin(), tree.end());

    int low = 1, high = maximum, ans = 0;

    while(low <= high){
        int mid = (low + high)/2;

        ll cnt = 0;  // 자른 랜선 개수 초기화
        for (int i=0; i<N; i++){
            cnt += max(0, tree[i]-mid);
        }

        // 가져가는 나무의 총 길이가 더 크거나 같으면
        if (cnt >= M){
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