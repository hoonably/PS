#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100

/*
A에 포함된 문자열로 S를 만들 수 있으면 1, 없으면 0

dfs로 풀었다가 시간초과 발생
=> 왜냐면 여러번 넣어도 되니 됐을때의 idx가 중요한건데, dfs로 하면
같은 길이인데 문자열이 다른게 있다면 여러번 진행함

dp로 풀어야함
*/

string S;
int Slen;
int N;
string A[MAX];
int len[MAX];

bool dp[101];

bool able(int idx, int a){
    // 문자열 길이 넘어감
    if (idx+len[a]>Slen) return false;

    for (int i=0; i<len[a]; i++){
        if (S[idx+i]!=A[a][i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> S;
    Slen = S.length();

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
        len[i] = A[i].length();
    }

    dp[0]=true;
    for (int i=0; i<Slen; i++){
        if (dp[i]){
            for (int j=0; j<N; j++){
                if (able(i, j)) dp[i+len[j]] = true;
            }
        }
    }
    cout << dp[Slen];
    
    return 0;
}