#include <bits/stdc++.h>
using namespace std;

/*
A+B*C-D/E  ->  ABC*+DE/-

stack으로 구현

연산자가 들어왔을때, 
우선순위가 크거나 같은 것들은 모두 출력하면서 빼주고,
모두 출력했다면 본인은 연산에 추가해준다.
*/

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    stack<char> operate;
    for (int i=0; i<s.length(); i++){

        // 바로 출력
        if ('A'<=s[i] && s[i]<='Z'){
            cout << s[i];
        }
        
        // 괄호가 나오는 경우
        else if (s[i]=='('){
            operate.push('(');
        }

        // 괄호를 닫는 경우
        else if (s[i]==')'){
            // '(' 나올때까지 모두 계산
            while(operate.top() != '('){
                cout << operate.top();
                operate.pop();
            }
            operate.pop();  // '(' 까지 제거 
        }

        // 우선순위 높은거
        // 자신보다 우선순위가 높은 것은 없고,
        // 우선순위가 같은 * 와 / 만 뺌
        // 어차피 *나 /는 최대 하나만 저장됨
        // 이유 : *가 두개 저장되려고 하면 이미 하나는 출력되어있음
        else if (s[i] == '*' || s[i] == '/') {


            if (!operate.empty() && 
            (operate.top() == '*' || operate.top() == '/')){
                cout << operate.top();
                operate.pop();
            }
            operate.push(s[i]);  // 마지막에 지금꺼 넣기
        }

        // 우선순위 낮은거
        // 이전의 우선순위가 높거나 같은 것들을 '모두' 출력해줌
        // '(' 나오기 전은 모두 우선순위가 높거나 같음
        else if (s[i] == '+' || s[i] == '-') {
            while (!operate.empty() && operate.top() != '(') {
                cout << operate.top();
                operate.pop();
            }
            operate.push(s[i]);
        }
    }

    // 남아있는 스택 모두 출력
    while (!operate.empty()) {
        cout << operate.top();
        operate.pop();
    }
    
    return 0;
}