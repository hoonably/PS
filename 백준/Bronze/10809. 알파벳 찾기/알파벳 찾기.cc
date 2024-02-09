#include <iostream>
using namespace std;

int main(void){
    string S;
    int locations[26];
    for (int i=0; i<26; i++){
        locations[i]=-1;
    }

    cin >> S;
    for (int i=0; S[i]!='\0'; i++){
        if (locations[S[i]-'a']==-1){
            locations[S[i]-'a']=i;
        }
    }
    for (int i=0; i<26; i++){
        cout << locations[i] << ' ';
    }
    return 0;
}