#include <iostream>
using namespace std;

int main(void) {
    string word;
    int cnt = 1, len;
    
    // getline()을 사용해 띄어쓰기 포함 한줄을 통째로 받기
    getline(cin, word);
    
    len = word.length();

    // 띄어쓰기만 있을 경우 0 출력
    if (len == 1 && word[0] == ' ') {
        cout << 0;
        return 0;
    }
    
    for (int i = 1; i < len - 1; i++) {
        if (word[i] == ' ') {
            cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}