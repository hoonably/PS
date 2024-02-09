#include <iostream>
using namespace std;

int main(void){
    string word;
    int alphabet[26] = {0};

    cin >> word;

    for (int i=0; i<word.length(); i++){
        if (word[i] <= 90){
            alphabet[word[i]-65]++;
        }
        else {
            alphabet[word[i]-97]++;
        }
    }

    int best_value = 0;
    int best_index = 0;
    int only = false;
    for (int j=0; j<26; j++){
        if (alphabet[j] > best_value){
            best_index = j;
            best_value = alphabet[j];
            only = true;
        }
        else if (alphabet[j] == best_value){
            only = false;
        }
    }

    // 가장 많이 사용된 알파벳이 하나
    if (only){
        cout << (char)(best_index+65);
    }
    else{
        cout << '?';
    }
    return 0;
}