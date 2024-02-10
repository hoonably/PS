#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    string name;
    set<string> not_heard, not_both;
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> name;
        not_heard.insert(name);
    }
    for (int i=0; i<M; i++){
        cin >> name;
        if (not_heard.find(name)!=not_heard.end()){
            not_both.insert(name);
        }
    }
    cout << not_both.size() << '\n';
    for (string n : not_both){
        cout << n << '\n';
    }
    
    return 0;
}