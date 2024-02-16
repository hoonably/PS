#include <bits/stdc++.h>
using namespace std;

/*
주의할점 : second가 같다면 first도 정렬을 해줘야한다.
ex)
1~5 , 5~5 인 회의 시간이 있다면 순서에 따라
1~5, 5~5는 할 수 있지만
5~5, 1~5는 못하는 회의로 판정이 난다.
*/

int N;
vector<pair<int, int>> v;

// pair vector second 값을 기준으로 정렬
bool compare(pair<int, int> &a, pair<int, int> &b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        int s, e;
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }
    // 끝나는 시간 기준으로 정렬
    sort(v.begin(), v.end(), compare);

    int cnt = 0, end_point = 0;
    for (int i=0; i<N; i++){
        // 마지막 회의가 끝난 시간 이후라면 count 하고 끝나는 시간 바꾸기
        if (end_point <= v[i].first){
            cnt++;
            end_point = v[i].second;
        }
        
    }
    cout << cnt;
    
    return 0;
}