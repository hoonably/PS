#include <iostream>
using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        string word;
        cin >> word;
        cout << word[0] << word[word.length()-1] << endl;
    }
    return 0;
}