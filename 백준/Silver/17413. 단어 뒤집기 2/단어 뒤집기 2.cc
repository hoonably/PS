#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
스택을 사용하여 뒤집는다.
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string S;
    getline(cin, S);  // 한 줄 입력 받기
    S += ' ';

    deque<char> dq;

    bool tag = false; // < > 내부인지
    for (char c : S){

        if (c=='<'){
            while(!dq.empty()){
                cout << dq.back();
                dq.pop_back();
            }
            cout << c;
            tag = true;
        }

        else if (c==' ' && !tag){
            while(!dq.empty()){
                cout << dq.back();
                dq.pop_back();
            }
            cout << c;
        }

        else if (c=='>'){
            while(!dq.empty()){
                cout << dq.front();
                dq.pop_front();
            }
            cout << c;
            tag = false;
        }
        
        else dq.push_back(c);
    }

    
    return 0;
}