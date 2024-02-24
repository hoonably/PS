#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
그냥 문자열로 하면 제거 과정에서 시간초과 발생.
하나씩 배열에 담아가면서, 마지막 b_len개가 동일하면 삭제하기
그리고 삭제했다면 다시 삭제한만큼 idx땡겨와서 계속 진행
*/

string str;
string bomb;
int slen, blen, idx;
char ans[1000000];

bool check(int start){
    for (int i = start; i < start + blen; ++i) 
        if (ans[i] != bomb[i - start]) 
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> str >> bomb;
    slen = str.length();
    blen = bomb.length();

    idx = 0;
    for (int i = 0; i < slen; i++) {
        ans[idx++] = str[i];
        if (idx >= blen && check(idx - blen))
            idx -= blen;  // idx를 뒤로 밀기
    }
    if (idx==0) {
        cout << "FRULA";
        return 0;
    }
    for (int i=0; i<idx; i++){
        cout << ans[i];
    }
    
    return 0;
}