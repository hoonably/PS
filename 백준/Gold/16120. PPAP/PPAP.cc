#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
A가 나왔을때 앞에 PP가 아니면 그 A는 절대로 못 없어짐 
*/

bool solve(){

    string str;
    cin >> str;

    int cntP = 0;// 앞에 있는 P의 개수
    bool lastA = false;  // 바로 전에 A가 나왔는지

    for (char c : str){
        
        if (lastA) {
            if (c=='P'){  // PPAP가 됨
                lastA = false;
                cntP--;  // PPAP 가 P로 바뀌는 것이므로 P가 하나 줄어야함
                continue;
            }
            else return false;  // A가 두번 연속으로 나옴
        }

        // P가 나온 경우
        if (c=='P') cntP++;

        // A가 나왔는데 전에 P가 두개 이상이었다면
        else if (cntP>=2) lastA = true;

        // A가 나왔는데 전에 P가 두개 미만이었라면
        else return false;
    }

    if (cntP==1 && !lastA) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if (solve()) cout << "PPAP";
    else cout << "NP";
    
    return 0;
}