#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int N;
int num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> num;
    }

    cout << "YES\n" << num * 111;

    
    return 0;
}