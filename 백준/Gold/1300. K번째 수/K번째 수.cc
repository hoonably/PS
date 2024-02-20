#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
의외로 이분탐색으로 풀 수 있다.

10 * 10 에서 30보다 작거나 같은 수의 개수
: 30을 모든 행으로 나눈 몫의 합

30//1 : 30 => 그러나 행의 개수 10을 넘을 수 없으니 10개
30//2 : 15 => 그러나 행의 개수 10을 넘을 수 없으니 10개
30//3 : 10개
30//4 : 7개
... 30까지 모두 나눈 몫들을 다 더하기

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    int start = 1;
    int end = K;

    int ans;

    while(start<=end){
        int mid = (start+end)/2;

        int rank = 0;
        // 1부터 N행까지 나눈 값 합하기
        for(int row=1; row<=N; row++){
            rank += min(mid/row, N);  // 최대는 행(N)
        }

        // 갯수가 K보다 크거나 같으면 mid 낮추기
        if (rank >= K){
            end = mid-1;
            ans = mid;
        }
        else {
            start = mid+1;
        }
    }
    cout << ans;
    
    return 0;
}