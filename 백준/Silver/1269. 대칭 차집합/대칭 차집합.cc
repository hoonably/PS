#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, num, cnt=0;
    set<int> A;
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> num;
        A.insert(num);
    }
    for (int i=0; i<M; i++){
        cin >> num;
        if (A.find(num)!=A.end()){
            cnt++;
        }
    }
    cout << N + M - 2 * cnt;
    
    return 0;
}