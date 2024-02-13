#include <bits/stdc++.h>
using namespace std;

/*
tuple을 사용해 x좌표, y좌표를  동시 저장

*/

int N, M, ans = 1e9;
vector<pair<int, int>> houses, chickens, new_chickens;
bool visited[13];

int dist(){
    int res = 0;
    for (auto h : houses){
        int temp = 1e9;
        for (auto c : new_chickens){
            int dist = abs(c.first-h.first) + abs(c.second-h.second);
            if (dist < temp) temp = dist;
        }
        res += temp;
    }
    return res;
}

void backtracking(int depth, int idx){
    
    if (depth == M){
        int temp = dist();
        if (temp < ans) ans = temp;
    }

    for (int i=idx; i<chickens.size(); i++){

        if (visited[i]) continue;

        visited[i] = true;
        new_chickens.push_back(chickens[i]);

        backtracking(depth + 1, i + 1);

        visited[i] = false;
        new_chickens.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int get_num;
            cin >> get_num;
            if (get_num==1) houses.push_back(make_pair(i, j));
            else if (get_num==2) chickens.push_back(make_pair(i, j));
        }
    }
    backtracking(0, 0);
    cout << ans;
    
    return 0;
}