#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
최대로 측정할 수 있는 무게 : 30 * 500

*/

int N , M, num;
int weight[30];  // 추
bool dp[15001] = {false};
bool temp[15001];

void makedp(int level){
    if (level == N){
        return;
    }
    int w = weight[level];

    // for문을 진행하면서 w 뿐만 아니라 2*w, 3*w true가 되므로 임시 복사 배열을 사용해야한다.

    for (int i=0; i<=15000; i++){
        temp[i] = dp[i];
    }
    
    // 1. 빼면 음수
    for (int i=0; i<w; i++){
        if (!temp[i]) continue;
        dp[i+w]=true;
        dp[w-i]=true;
    }
    // 2. 빼면 양수
    for (int i=w; i<=15000; i++){
        if (!temp[i]) continue;
        dp[i+w]=true;
        dp[i-w]=true;
    }
    makedp(level+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> weight[i];
    }

    dp[0] = true;
    makedp(0);

    cin >> M;
    for (int i=0; i<M; i++){
        cin >> num;
        // 구슬 최대 index인 15000을 넘으면 무조건 N반환
        if (num>15000) cout << "N ";
        else if (dp[num]) cout << "Y ";
        else cout << "N ";
    }
    
    return 0;
}