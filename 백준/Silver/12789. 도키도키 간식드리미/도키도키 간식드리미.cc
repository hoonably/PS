#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, arr[1001];
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    stack<int> wait;
    wait.push(-1);  // 빈 스택 에러방지

    int now = 1;

    for (int i=1; i<=N; i++){

        while(wait.top()!=i){
            wait.push(arr[now]);
            now++;
            if (now==N+2){
                cout << "Sad";
                return 0;
            }
        }
        wait.pop();
    }

    // 위의 for문을 돌렸는데 스택에 -1 외에 더 남아있다면 못준거임
    wait.pop();  // -1 삭제
    if (wait.empty()) cout << "Nice";
    else cout << "Sad";
    
    return 0;
}