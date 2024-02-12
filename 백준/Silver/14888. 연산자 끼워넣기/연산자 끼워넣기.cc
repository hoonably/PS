#include <iostream>
#include <vector>

using namespace std;

int N; 
int num[11]; // 수 리스트
int operatorCount[4]; // 각 연산자의 개수 [+,-,×,÷]
vector<int> ansList; // 결과값 리스트
int answer = 0;

void solve(int n) {
    if (n == N) {
        ansList.push_back(answer);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (operatorCount[i] == 0) continue;
        int temp = answer;

        operatorCount[i]--;  // 사용

        switch (i) {
            case 0:
                answer += num[n]; break;
            case 1:
                answer -= num[n]; break;
            case 2:
                answer *= num[n]; break;
            case 3:
                answer /= num[n]; break;
        }

        solve(n + 1);

        // 백트래킹
        answer = temp;
        operatorCount[i]++;
    }
}

int main() {
    cin >> N; // 수의 개수 입력

    for (int i = 0; i < N; ++i) {
        cin >> num[i]; // 수 입력
    }

    for (int i = 0; i < 4; ++i) {
        cin >> operatorCount[i]; // 연산자 개수 입력
    }

    answer = num[0];
    solve(1); // 함수 호출

    // 결과 출력
    int min = ansList[0];
    int max = ansList[0];
    for (int i=1; i<ansList.size(); i++){
        if (ansList[i]>max) max = ansList[i];
        else if (ansList[i]<min) min = ansList[i];
    }
    cout << max << '\n' << min;

    return 0;
}
