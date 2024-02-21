#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
S(k) = S(k-1)   +   o가 k+2개인 수열 "m o ... o"   +   S(k-1)

S(0) = "m o o"
S(1) = "m o o  /  m o o o  /  m o o"
S(2) = "m o o m o o o m o o  /  m o o o o  /  m o o m o o o m o o"
*/

int N;
int k;
int len[28];

char solve(int level, int rank){
    if (level==0){
        if (rank==1) return 'm';
        else return 'o';
    }
    // 앞부분
    if (rank <= len[level-1]){
        return solve(level-1, rank);
    }
    // 뒷부분
    if (rank >= len[level] - len[level-1]){
        return solve(level-1, rank-(len[level] - len[level-1]));
    }
    // 가운데 부분 중에 맨 앞 'm'
    if (rank == len[level-1] + 1){
        return 'm';
    }
    // 가운데 부분 중에 뒷부분
    else {
        return 'o';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    k = 0;      // 단계
    len[0]=3;   // 길이
    while(len[k]<N){
        k++;
        len[k] = 2*len[k-1] + k+3;
    }
    cout << solve(k, N);
    
    return 0;
}