#include <iostream>
using namespace std;

int main(void){
    int T, R;
    cin >> T;
    for (int i=0; i<T; i++){
        string word;

        cin >> R;
        cin >> word;
        for (int j=0; j<word.length(); j++){
            for (int k=0; k<R; k++){
                cout << word[j];
            }
        }
        cout << endl;
    }
    return 0;
}