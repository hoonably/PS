#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
생각보다 까다로운 문제.
헤맸다.
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, K;
    string num;
    cin >> N >> K;
    cin >> num;

    int Notprint = K;
    // 출력 안해야 할 기회가 있는 경우
    // 덱에 넣은 마지막 값보다 현재 넣으려던게 크면 
    // 출력 안할거니까 빼주기
    deque<char> dq;
    for (int i=0; i<N; i++){
        while(Notprint>0 && !dq.empty() && num[i] > dq.back()){
            dq.pop_back();
            Notprint--;
        }
        dq.push_back(num[i]);
    }

    // dq.empty() 까지 하면 틀림
    // 덱에 문자가 남아있을 수도 있음
    // ex) 54321을 넣는 경우
    // 모두 남아있지만 2개를 뺀다면 543까지만 출력
    for(int i=0; i<N-K; i++){
        cout << dq.front();
        dq.pop_front();
    }
    
    return 0;
}