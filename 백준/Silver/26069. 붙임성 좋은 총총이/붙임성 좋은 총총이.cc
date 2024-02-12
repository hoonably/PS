#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<string> dance;
    dance.insert("ChongChong");

    int N;
    string A, B;
    cin >> N;
    
    while(N--){
        cin >> A >> B;
        // find(요소) : 요소가 나오면 그 주소 반환
        // 그러므로 반환값이 end 주소라면 없는것임
        if (dance.find(A) == dance.end() && dance.find(B) != dance.end()){
            dance.insert(A);
        }
        else if (dance.find(A) != dance.end() && dance.find(B) == dance.end()){
            dance.insert(B);
        }
    }

    cout << dance.size();
    
    return 0;
}