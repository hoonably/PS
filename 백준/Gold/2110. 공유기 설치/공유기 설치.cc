#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
생각하기 매우 어려움

# 설치 간격으로 이분탐색
# 설치 간격을 mid로 잡고 설치해봤더니
# 공유기의 수가 C보다 많다면 간격을 늘려야하니 mid~end 부분 탐색
# 공유기의 수가 C보다 부족하다면 간격을 줄여야하니 start~mid 부분 탐색
*/

int N, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> C;
    vector<int> x(N);
    for(int i=0; i<N; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    
    
    int start = 1; // 설치 간격 최소값
    int end = x[N-1] - x[0]; // 설치 간격 최대값
    int ans;

    while (start<=end){
        int mid = (start+end)/2;

        // 마지막으로 설치한 공유기의 위치
        int last_loc = x[0];
        // 공유기의 수 (1부터)
        int cnt = 1;

        for (int i=0; i<N; i++){
            // 마지막에 설치한곳과 거리가 mid(설치간격) 이상 떨어져있다면 설치
            if (x[i]-last_loc >= mid){
                cnt++;
                last_loc = x[i];
            }
        }
        
        // 설치한 공유기의 개수가 더 많거나 같다면 간격을 늘려야하니 mid~end 부분 탐색
        if (cnt >= C){
            start = mid+1;
            ans = mid;
        }
        // 공유기의 수가 C보다 부족하다면 간격을 줄여야하니 start~mid 부분 탐색
        else{
            end = mid-1;
        }
    }

    cout << ans;
    
    return 0;
}