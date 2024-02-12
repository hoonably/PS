#include <bits/stdc++.h>
using namespace std;

int N, M;
string str;
bool visited[9];

void combination(int depth, int start){
    if (depth == M){
        cout << str << "\n";
        return;
    }
    for (int i = start + 1; i <= N; i++){
        if (visited[i]) continue;
        visited[i] = true;
        str.push_back(i + '0');
        str.push_back(' ');
        combination(depth + 1, i);
        visited[i] = false;
        str.pop_back();
        str.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    combination(0, 0);
}