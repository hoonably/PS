#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 10

/*

*/

int N;
char A[MAX];

void backtracking(int level, int res, int last){
    if (level==N+1){
        if (res + last == 0){
            cout << 1;
            for (int i=2; i<=N; i++){
                cout << A[i] << i;
            }
            cout << '\n';
        }
        return;
    }
    // 공백 추가
    A[level]=' ';
    if (last<0) backtracking(level+1, res, last*10 - level);
    else backtracking(level+1, res, last*10 + level);

    // + 추가
    A[level]='+';
    backtracking(level+1, res+last, level);

    // - 추가
    A[level]='-';
    backtracking(level+1, res+last, -level);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        backtracking(2, 0, 1);
        cout << '\n';
    }
    
    return 0;
}