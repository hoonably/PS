#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, num;
    string order;
    queue<int> Q;  // 큐 선언

    cin >> N;
    while (N--){
        cin >> order;
        switch (order[1]) {
            case 'u':
                cin >> num;
                Q.push(num);
                break;
            case 'o':
                if (Q.empty()) cout << -1 << '\n';
                else {
                    cout << Q.front() << '\n';
                    Q.pop();
                }
                break;
            case 'i':
                cout<<Q.size()<<'\n';
                break;
            case 'm':
                if (Q.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 'r':
                if (Q.empty()) cout << -1 << '\n';
                else cout << Q.front() << '\n';
                break;
            case 'a':
                if (Q.empty()) cout << -1 << '\n';
                else cout << Q.back() << '\n';
                break;
            default:
                break;
        }
    }
    
    return 0;
}