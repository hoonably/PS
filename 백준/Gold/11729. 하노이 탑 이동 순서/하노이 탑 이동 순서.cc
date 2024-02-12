#include <iostream>
using namespace std;

void hanoi(int n, int start, int end) {
    if (n == 1) {
        cout << start << ' ' << end << '\n';
        return;
    }

    // 옮기려는 곳 말고 다른 곳으로 옮기기
    // 6-start-end를 하면 start와 end 외의 곳이다.
    int not_start_end = 6 - start - end;

    // 1단계: 마지막 것을 제외한 모든 것을 옮긴다.
    hanoi(n - 1, start, not_start_end);

    // 2단계: 마지막 것을 옮긴다.
    cout << start << ' ' << end << '\n';

    // 3단계: 1단계에서 옮겨서 남은 1 ~ n-1 번을 end로 옮긴다.
    hanoi(n - 1, not_start_end, end);
}

int main() {
    int N;
    cin >> N;

    // 옮긴 횟수: 2의 N승 - 1번
    cout << (1 << N) - 1 << '\n';

    // 1~N번을 1번 자리에서 3번 자리로 옮긴다.
    hanoi(N, 1, 3);

    return 0;
}
