#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 100000

/*
Graham scan 알고리즘을 통한 볼록 껍질 구하기

주어진 점들을 반시계방향으로 정렬하고, 정렬된 순서대로 점들을 탐색한다.
stack에 첫 번째 점과 두 번째 점을 push 해준다. 

그 다음 세 번째 점부터 N번째 점까지 다음의 과정을 반복할 것이다.
만약 stack의 최상단에 있는 두 점을 이은 직선에 대해, 현재 탐색하는 정점이 직선의 왼쪽에 존재한다면 stack에 push한다.
그렇지 않다면 stack을 pop하고 위 조건을 다시 확인한다.

최종적으로 탐색이 끝나면 stack에는 Convex Hull을 구성하는 점들이 포함되어 있다.
*/

struct dot {
    ll x,y;
};

dot CH[MAX];  // Convex Hull

ll ccw(dot a, dot b, dot c) {
    // 양수라면 반시계방향
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool compare(dot a, dot b){ //반시계 정렬
    
    ll cc = ccw(CH[0], a, b);
    if (cc) // 0 번 점을 기준으로 각도가 작은 순
        return cc > 0;
    else if (a.x != b.x) //x가 작은 순
        return a.x < b.x;
    else //y가 작은 순
        return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;  // n은 무의미한것
    cin >> n;

    int N = 0;
    for (int i=0; i<n; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c=='Y'){
            CH[N].x = x;
            CH[N].y = y;
            N++;
        }
    }
    
    // x좌표가 가장 작거나, 같다면 y좌표가 가장 작은 점이 CH[0]에 오도록 정렬
    for (int i=1; i<N; i++){
        if(CH[i].x < CH[0].x || (CH[i].x == CH[0].x && CH[i].y < CH[0].y)){
            swap(CH[0].x, CH[i].x);
            swap(CH[0].y, CH[i].y);
        }
    }
    
    sort(CH+1, CH+N, compare);
    
// 시작점으로 돌아올 때 직선에 점이 여러개인 경우
// 본래와 다르게 반대로 x, y좌표가 점점 작아지도록 순서를 거꾸로 바꿔줘야 함

/* ex)
6
0 0 Y
1 0 Y
2 0 Y
2 1 Y
2 2 Y
1 1 Y
*/  

    // 처음과 마지막에서 180도가 안나올때까지 idx 내리기
	int idx = N-1;
    while(ccw(CH[0], CH[idx], CH[idx - 1])==0){
        idx--;
    }
	reverse(CH+idx, CH+N);

	cout << N << '\n';
	for(int i=0; i<N; i++){
		cout << CH[i].x << ' ' << CH[i].y << '\n';
    }

    return 0;
}