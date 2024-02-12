#include <bits/stdc++.h>
using namespace std;

string S, T;

bool check(int depth, const string str){

    // 글자수가 같다면
    if (depth == 0){
        if (str == S) return true;
        else return false;
    }

    // A를 뒤에서 삭제시키는 경우
    if (str.back() == 'A'){
        string temp = str;
        temp.pop_back();
        if (check(depth-1, temp)) return true;
    }

    // B를 앞에서 삭제시키고 뒤집는 경우
    if (str.front() == 'B'){
        string temp = str;
        reverse(temp.begin(), temp.end());
        temp.pop_back();
        if (check(depth-1, temp)) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> T;
    int total_level = T.length() - S.length();
    if (check(total_level, T)) cout << 1;
    else cout << 0;
    
    return 0;
}