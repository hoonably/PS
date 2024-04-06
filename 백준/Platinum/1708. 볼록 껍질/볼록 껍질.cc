#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기
주어진 점들을 반시계방향으로 정렬하고, 정렬된 순서대로 점들을 탐색한다..
stack에 첫 번째 점과 두 번째 점을 push 해준다. 그 다음 세 번째 점부터 N번째 점까지 다음의 과정을 반복할 것이다.
만약 stack의 최상단에 있는 두 점을 이은 직선에 대해, 현재 탐색하는 정점이 직선의 왼쪽에 존재한다면 stack에 push한다.
그렇지 않다면 stack을 pop하고 위 조건을 다시 확인한다.
최종적으로 탐색이 끝나면 stack에는 Convex Hull을 구성하는 점들이 포함되어 있다.
*/

struct dot {
    ll x,y;
};

vector <dot> v;
stack <dot> s;

ll ccw(dot a, dot b, dot c) {
    // 양수라면 반시계방향
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool compare(dot a, dot b){ //반시계 정렬
    
    ll cc = ccw(v[0], a, b);
    if (cc) // 0 번 점을 기준으로 각도가 작은 순
        return cc > 0;
    else if (a.y != b.y) //y가 작은 순
        return a.y < b.y;
    else //x가 작은 순
        return a.x < b.x;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N;
    cin >> N;
    
    v.resize(N);
    for (int i=0; i<N; i++){
        cin >> v[i].x >> v[i].y;
    }
    
    // y좌표와 x좌표가 가장 작은 점이 v[0]에 오도록 정렬
    for (int i=1; i<N; i++){
        if(v[i].y < v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x)){
            swap(v[0].x, v[i].x);
            swap(v[0].y, v[i].y);
        }
    }
    
    sort(v.begin()+1, v.end(), compare);
    
    // 볼록껍질 검사
    s.push(v[0]);
    s.push(v[1]);
    for(int i=2; i<N; i++){
        while (s.size() >= 2){
            
            // 상위 두개의 원소 반시계인지 비교
            dot top2 = s.top();
            s.pop();
            dot top1 = s.top();

            // 반시계방향이라면 다시 넣고 종료
            if (ccw(top1, top2, v[i]) > 0){
                s.push(top2);
                break;
            }
        }
        s.push(v[i]);
    }
    
    cout << s.size();
    
    return 0;
}