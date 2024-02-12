#include <bits/stdc++.h>
using namespace std;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque<int> D;
    int N, M, num, ans = 0;

    cin >> N >> M;
    for (int i=1; i<=N; i++){
        D.push_back(i);
    }

    for (int i=0; i<M; i++){
        cin >> num;
        int temp = 0;
        while(D.front()!=num){
            D.push_front(D.back());
            D.pop_back();
            temp++;
        }
        D.pop_front();
        if (2 * temp < N-i) ans += temp;
        else ans += (N-i) - temp;
    }
    cout << ans;

    return 0;
}