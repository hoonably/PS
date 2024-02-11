#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    queue<int> circle;
    vector<int> ans;
    
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        circle.push(i);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K-1; j++){
            circle.push(circle.front());
            circle.pop();
        }   
        ans.push_back(circle.front());
        circle.pop();
    }

    cout << '<' ;
    for(int i=0; i<N-1; i++){
        cout << ans[i] << ", ";
    }
    cout << ans[N-1] << '>';


    return 0;
}