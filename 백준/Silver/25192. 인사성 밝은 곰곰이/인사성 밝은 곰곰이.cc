#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<string> gomgom;
    int N, cnt = 0;
    string chat;
    cin >> N;
    
    while(N--){
        cin >> chat;
        if(chat=="ENTER"){
            cnt += gomgom.size();
            gomgom.clear();
        }
        else{
            gomgom.insert(chat);
        }
    }
    cnt += gomgom.size();
    cout << cnt;
    
    return 0;
}