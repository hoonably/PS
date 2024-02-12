#include <bits/stdc++.h>
using namespace std;

/*
1차원 리스트의 각 원소가 string으로 '한줄'을 입력하도록 한다.
줄바꿈 없이 원소들을 저장 후 출력할때 줄바꿈만 해준다.
줄바꿈을 미리 저장하면 재귀를 할때마다 줄이 바뀐다.
*/

vector<string> star(int n){

    vector<string> result;

    // 기본 별 하나
    if (n==1) {
        result.push_back("*");
        return result;
    }

    // 재귀로 벡터 불러오기
    vector<string> last_star = star(n/3);

    for (string line : last_star){
        string temp = line + line + line;
        result.push_back(temp);
    }

    for (string line : last_star){
        string temp = line;
        for (int i=0; i<n/3; i++) temp += ' ';  // 띄어쓰기 n/3번
        temp += line;
        result.push_back(temp);
    }

    for (string line : last_star){
        string temp = line + line + line;
        result.push_back(temp);
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (string line : star(N)){
        cout << line << '\n';
    }
    
    return 0;
}