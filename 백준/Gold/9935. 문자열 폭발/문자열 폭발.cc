#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
그냥 문자열로 하면 제거 과정에서 시간초과 발생.
하나씩 배열에 담아가면서, 마지막 b_len개가 동일하면 삭제하기
그리고 삭제했다면 다시 삭제한만큼 idx땡겨와서 계속 진행
*/

string word, bomb, ans;
int b_len;

// 현재 ans의 뒤부분이 폭탄과 같은지 체크
bool check(){
    for (int i = 1; i <= b_len; i++) {
        if (bomb[b_len - i] != ans[ans.length() - i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> word >> bomb;
    b_len = bomb.length();

    for (char c : word) {
        ans += c;
        // c가 폭탄 마지막 글자이면서 res의 길이가 폭탄의 크기 이상이면 체크
        if (c == bomb[b_len - 1] && ans.size() >= bomb.size()) {

            if (check()) ans.erase(ans.end() - b_len, ans.end());
        }
    }

    if (ans.empty()) cout << "FRULA";
    else cout << ans;

    return 0;
}