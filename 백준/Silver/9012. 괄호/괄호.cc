#include <bits/stdc++.h>
using namespace std;

bool check(const string& str) {
    stack<int> stack;
    for (char s : str) {
        if (s == '(') {
            stack.push(0);
        } else if (s == ')') {
            if (stack.empty()) {
                return false;
            } else {
                stack.pop();
            }
        }
    }
    return stack.empty();  // 비어있다면 true 아니면 false
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    string str;
    cin >> T;
    while (T--){
        cin >> str;
        if (check(str)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}