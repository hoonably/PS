#include <iostream>
#include <string>
using namespace std;


int N, M;
string str;

void go(int d){
    if (d == M){
        cout << str << "\n";
        return;
    }
    for (int i = 1; i <= N; i++){
        str.push_back(i + '0');
        str.push_back(' ');
        go(d + 1);
        str.pop_back();
        str.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    go(0);
}