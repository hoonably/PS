#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, order;
    stack<int> S;  // 스택 선언

    cin >> N;
    while (N--){
        cin >> order;
        switch (order) {
            case 1:
                cin >> order;
                S.push(order);
                break;
            case 2:
                if (S.empty()) cout << -1 << '\n';
                else {
                    cout << S.top() << '\n';
                    S.pop();
                }
                break;
            case 3:
                cout<<S.size()<<'\n';
                break;
            case 4:
                if (S.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 5:
                if (S.empty()) cout << -1 << '\n';
                else cout << S.top() << '\n';
                break;
            default:
                break;
        }
    }
    
    return 0;
}