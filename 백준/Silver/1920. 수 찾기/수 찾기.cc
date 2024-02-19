#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

bool binary_search(vector<int> &array, int target) {
    int low = 0;
    int high = array.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == target) return true;
        else if (array[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cin >> M;
    for (int i=0; i<M; i++){
        int x;
        cin >> x;
        cout << binary_search(A, x) << '\n';
    }
    
    return 0;
}