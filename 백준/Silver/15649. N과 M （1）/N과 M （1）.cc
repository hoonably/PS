#include <bits/stdc++.h>
using namespace std;

int N, M;
string str;
bool visited[9];

void permutation(int depth){
    if (depth == M){
        cout << str << "\n";
        return;
    }
    for (int i = 1; i <= N; i++){
        if (visited[i]) continue;
        visited[i] = true;
        str.push_back(i + '0');
        str.push_back(' ');
        permutation(depth + 1);
        visited[i] = false;
        str.pop_back();
        str.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    permutation(0);
}