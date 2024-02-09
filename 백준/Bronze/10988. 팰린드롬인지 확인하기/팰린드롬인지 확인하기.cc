#include <iostream>
using namespace std;

int main(){
    string word;
    cin >> word;
    int len = word.length();
    for (int i=0; i<len/2; i++){
        if (word[i]!=word[len-i-1]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}