#include <iostream>
using namespace std;

int main(void){
    string get_word;
    int alphabet, cnt=0;
    cin >> get_word;
    for (int i=0; i < get_word.length(); i++){
        alphabet = get_word[i];

        if(alphabet <= 'C'){
            cnt += 3;
        }
        else if(alphabet <= 'F'){
            cnt += 4;
        }
        else if(alphabet <= 'I'){
            cnt += 5;
        }
        else if(alphabet <= 'L'){
            cnt += 6;
        }
        else if(alphabet <= 'O'){
            cnt += 7;
        }
        else if(alphabet <= 'S'){
            cnt += 8;
        }
        else if(alphabet <= 'V'){
            cnt += 9;
        }
        else if(alphabet <= 'Z'){
            cnt += 10;
        }
    }
    cout << cnt;
    return 0;
}