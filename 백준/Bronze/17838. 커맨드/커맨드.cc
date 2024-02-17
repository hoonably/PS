#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        string combo;
        cin >> combo;

        if (combo.length() != 7 || combo[0] == combo[2]) {
            cout << 0 << '\n';
            continue;
        }

        if (combo[0] == combo[1] && combo[1] == combo[4] && combo[2] == combo[3] && combo[3] == combo[5] && combo[5] == combo[6]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
