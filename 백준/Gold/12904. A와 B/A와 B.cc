#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string S, T;
    cin >> S >> T;


    
    // T의 마지막 인덱스
    int idx = T.length() - 1;
    deque<int> dq;
    for (int i=0; i<=idx; i++){
        dq.push_back(T[i]);
    }

    int level = T.length() - S.length();
    
    bool reversed = false;

    while(level--){

        if (!reversed){
            if (dq.back()=='A'){
                dq.pop_back();
            }
            else {
                reversed = true;
                dq.pop_back();
            }
        }

        // 반전된 상태라면
        else{
            if (dq.front()=='A'){
                dq.pop_front();
            }
            else {
                reversed = false;
                dq.pop_front();
            }
        }
    }
    
    if (!reversed){
        for (char c : S){
            // 일치하지 않는게 있다면
            if (dq.front()!=c){
                cout << 0;
                return 0;
            }
            dq.pop_front();
        }
    }
    else{
        for (char c : S){
            // 일치하지 않는게 있다면
            if (dq.back()!=c){
                cout << 0;
                return 0;
            }
            dq.pop_back();
        }
    }

    
    // 모두 일치한다면
    cout << 1;
    

    return 0;
}