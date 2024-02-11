#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, order;
    deque<int> D;  // 덱 선언

    cin >> N;
    while (N--){
        cin >> order;
        switch (order) {
            case 1:
                cin >> order;
                D.push_front(order);
                break;
            case 2:
                cin >> order;
                D.push_back(order);
                break;
            case 3:
                if (D.empty()) cout << -1 << '\n';
                else {
                    cout << D.front() << '\n';
                    D.pop_front();
                }
                break;
            case 4:
                if (D.empty()) cout << -1 << '\n';
                else {
                    cout << D.back() << '\n';
                    D.pop_back();
                }
                break;
            case 5:
                cout<<D.size()<<'\n';
                break;
            case 6:
                if (D.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 7:
                if (D.empty()) cout << -1 << '\n';
                else cout << D.front() << '\n';
                break;
            case 8:
                if (D.empty()) cout << -1 << '\n';
                else cout << D.back() << '\n';
                break;
            default:
                break;
        }
    }
    
    return 0;
}