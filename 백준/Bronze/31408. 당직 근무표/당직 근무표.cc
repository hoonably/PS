#include <bits/stdc++.h>
using namespace std;

/*
가장 많은 것이 총 자리의 총 개수의 반 까지는 가능하다.
남아있는 자리가 5이면, 3까지 가능
N 이면 (N+1)/2 까지 가능
*/

int N, num;
int schedule[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> num;
        schedule[num]++;
        if (schedule[num]>(N+1)/2){
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    
    return 0;
}