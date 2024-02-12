#include <bits/stdc++.h>
using namespace std;

string kantore(int n) {
    if (n == 0) {
        return "-";
    }
    string str = kantore(n - 1);
    for (int i=0; i<pow(3,n-1); i++){
        str += ' ';
    }
    str += kantore(n - 1);
    return str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (!(cin >> N).eof()) {
        cout << kantore(N) << '\n';
    }

    return 0;
}
