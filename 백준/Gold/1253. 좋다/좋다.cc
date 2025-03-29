// Purpose: "좋은 수(GOOD)"의 개수 세기 (삼항 이분 탐색 활용)
// Usage: 각 A[i]에 대해 A[j] + A[k] == A[i] 인 (j, k)를 binary_search_exact로 찾음
// Time Complexity: O(N^2 * logN)

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

// 삼항 비교 기반 이분 탐색 함수들
int binary_search_exact(int lo, int hi, function<int(int)> check) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int res = check(mid);
        if (res == 0) return mid;
        else if (res < 0) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    sort(all(A));
    int good = 0;

    for (int i = 0; i < N; ++i) {
        bool found = false;

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            ll target = A[i] - A[j];

            // check 함수 정의
            auto check = [&](int k) -> int {
                if (k == i || k == j) return 1;  // 무시할 인덱스
                if (A[k] == target) return 0;
                else if (A[k] < target) return -1;
                else return 1;
            };

            int idx = binary_search_exact(0, N - 1, check);
            if (idx != -1) {
                found = true;
                break;
            }
        }

        if (found) good++;
    }

    cout << good << '\n';
    return 0;
}
