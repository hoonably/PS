#include <bits/stdc++.h>
using namespace std;

/*

*/

int N, S, cnt = 0;
int arr[20];


void backtracking(int idx, int tmp) {

	if (idx == N) return;
	if (tmp + arr[idx] == S) cnt++;

	backtracking(idx + 1, tmp);
	backtracking(idx + 1, tmp + arr[idx]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }   
    backtracking(0, 0);
    cout << cnt;

    return 0;
}