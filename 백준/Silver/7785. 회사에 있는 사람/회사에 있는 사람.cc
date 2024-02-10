#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, cnt=0;
    string name, status;
    // 오름차순 집합 선언 (중요!!)
    set<string,greater<string>> company;
    
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> name >> status;
        if (status=="enter"){
            company.insert(name);
        }
        else {
            company.erase(name);
        }
    }

    for (string s : company){
        cout << s << '\n';
    }

    return 0;
}