#include <bits/stdc++.h>
using namespace std;

/*
S = A[0] × B[0] + ... + A[N-1] × B[N-1]
S의 값을 가장 작게 만들기 위해 A의 수를 재배열
*/

int N;
int A[50], B[50];

// 역순 정렬 하기 위해
bool compare(int a, int b) {
	return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N, compare);  // 역순 정렬

    int ans = 0;
    for(int i=0; i<N; i++){
        ans += A[i]*B[i];
    }
    cout << ans;

    return 0;
}