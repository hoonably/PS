#include <bits/stdc++.h>
using namespace std;

int N, M;
string str;

void combination(int depth, int start){
    if (depth == M){
        cout << str << "\n";
        return;
    }
    for (int i = start; i <= N; i++){
        str.push_back(i + '0');
        str.push_back(' ');
        combination(depth + 1, i);
        str.pop_back();
        str.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    combination(0, 1);
}