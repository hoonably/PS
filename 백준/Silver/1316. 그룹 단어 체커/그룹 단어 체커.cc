#include <iostream>
using namespace std;

int main(){
    int N, cnt;
    cin >> N;
    cnt = N;
    for (int i=0; i<N; i++){
        bool alphabet[26] = {false, };
        string word;
        char last;
        cin >> word;
        
        for (int j=0; j<word.length(); j++){
            char temp = word[j];
            //  이전꺼랑 다르면서 이미 나왔던 알파벳이라면
            if (temp != last && alphabet[temp-97] == true){
                cnt--;
                break;
            }
            last = temp;  // 마지막 알파벳 저장
            alphabet[temp-97] = true;  // 나온거 표시
        }
    }
    cout << cnt;

    return 0;
}