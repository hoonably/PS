#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int get, num;
    int max, min;
    cin >> get;

    cin >> max;
    min = max;
    while(--get){
        cin >> num;
        if (num > max) max = num;
        if (num < min) min = num;
    }
    cout << min*max;

    

    return 0;
}