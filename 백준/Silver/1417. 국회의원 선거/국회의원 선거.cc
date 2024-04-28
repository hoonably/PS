#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*

*/

int Dasom;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    cin >> Dasom;
    int start = Dasom;

    if (N==1) {
        cout << 0;
        exit(0);
    }

    priority_queue<int> pq;
    for (int i=0; i<N-1; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    
    while(true){
        int big = pq.top();
        pq.pop();
        if (big<Dasom) break;

        Dasom++;
        pq.push(big-1);
    }
    cout << Dasom - start;
    
    return 0;
}