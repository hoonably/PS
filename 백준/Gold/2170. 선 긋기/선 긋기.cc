#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'000

/*
시작 지점에 대해서 정렬

앞으로 나아가면서 가장 오른쪽에 있는 것보다 왼쪽에 시작한다면
기존 선분이랑 이을 수 있음

반대로 가장 오른쪽에 있던 것보다 더 오른쪽에서 시작한다면
떨어져있는 선분 생성하니 기존 선분 답에 추가

*/

struct LINE {
    int start;
    int end;
};

int N;
LINE line[MAX];

// 시작 지점에 대해서만 정렬
bool compare(LINE a, LINE b){
    return a.start < b.start;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> line[i].start >> line[i].end;
    }

    sort(line, line+N, compare);

    int ans = 0;
    int left = line[0].start;
    int right = line[0].end;

    for (int i=1; i<N; i++){

        // 가장 오른쪽에 있는 것보다 왼쪽에 시작한다면
        // 기존 선분이랑 이을 수 있음
        if (line[i].start < right) {
            right = max(right, line[i].end);
        }

        // 가장 오른쪽에 있던 것보다 더 오른쪽에서 시작한다면
        // 떨어져있는 선분 생성하니 기존 선분 답에 추가
        else {
            ans += right - left;
            left = line[i].start;
            right = line[i].end;
        }
    }
    ans += right - left;
    cout << ans;
    
    return 0;
}