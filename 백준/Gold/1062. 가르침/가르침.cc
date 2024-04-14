#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
비트마스킹 + 백트래킹
K개의 글자를 가르칠때, 읽을 수 있는 단어의 개수

antic 는 무조건 들어가야 함 -> K<5 라면 답은 0

미리 각 단어에 대해 필요한 bit를 만들어놓고, 
확인할때 현재 bit와 단어의 bit를 AND 연산을 이용해 단어의 bit와 같다면 
그 단어를 만들 수 있는것이다.
*/

int N, K;
string words[50];
int wordsBit[50];
int ans;

void backtracking(int bit, int level, int last){
    // K개의 글자를 가르쳤다면
    if (level==K){
        int cnt=0;
        for (int i=0; i<N; i++){
            if ((bit & wordsBit[i]) == wordsBit[i]) cnt++;
        }
        if(cnt==N){  // N개 모두 가능하면 바로 종료
            cout << N;
            exit(0);
        }
        ans = max(ans, cnt);  // ans 업데이트
    }

    // 현재 안켜져있는 비트에 대해 backtracking
    for (int i = last+1; i < 26; ++i){
        // i번 비트가 0이라면 켜주고 재귀
        if (!(bit & (1 << i)))
            backtracking(bit | (1 << i), level + 1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> words[i];
    }

    // 5개 미만이면 절대 못만들음
    if (K<5) {
        cout << 0;
        exit(0);
    }

    int bit = 0b00000010000010000100000101;  // 2진수로 a, c, i, n, t 켜줌

    // 미리 각 단어에 대해 필요한 bit를 만들어놓기
    for (int i=0; i<N; i++){
        wordsBit[i] = 0b00000010000010000100000101;
        string word = words[i];
        for (int j=4; j<word.length()-4; j++){
            wordsBit[i] |= 1 << (word[j]-'a');  // 알파벳에 맞는 비트를 켜주기
        }
        // cout << bitset<26>(wordsBit[i]) << '\n';  // 확인
    }
    
    // 이미 5개의 글자는 가르쳤으니 진행도는 5로 시작
    backtracking(bit, 5, -1);

    cout << ans;
    
    return 0;
}