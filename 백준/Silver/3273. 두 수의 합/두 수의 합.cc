#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
투 포인터 알고리즘
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    cin >> x;
    
	int cnt = 0;
	int l = 0, r = n - 1;

	while (l < r) {
		if (arr[l] + arr[r] == x) {
			cnt += 1;
			l += 1;
			r -= 1;
		}
		else if (arr[l] + arr[r] > x) r -= 1;
		else l += 1;
	}
    cout << cnt;
    
    return 0;
}