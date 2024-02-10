#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int arr[500001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    while(m--) {
        cin >> x;
        cout << upper_bound(arr, arr+n, x) - lower_bound(arr, arr+n, x) << ' ';
    }
}