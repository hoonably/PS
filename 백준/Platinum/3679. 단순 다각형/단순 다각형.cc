#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 2001

/*
이 문제는 이미 볼록 껍질을 이루는 점이 나와있고, 순서대로 출력만 하면 된다.
굳이 볼록 껍질을 구하는 Graham scan 알고리즘을 사용할 필요 없이, 정렬만 잘 해주면 된다.

하지만, 이 문제에서는 같은 직선 내에서도 여러 점이 볼록껍질을 이루는 점으로 나와있어서,
조심해야한다.

특히, 마지막에 돌아올때 직선에 점이 여러개 있으면 순서를 반대로 바꿔줘야한다.
*/

struct dot {
    int x, y, idx;
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
    else if (a.y != b.y) //y가 작은 순
        return a.y < b.y;
    else //x가 작은 순
        return a.x < b.x;
}

void solve(){

    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> CH[i].x >> CH[i].y;
        CH[i].idx = i;
    }
    
    // y좌표와 x좌표가 가장 작은 점이 CH[0]에 오도록 변경
    for (int i=1; i<N; i++){
        if(CH[i].y < CH[0].y || (CH[i].y == CH[0].y && CH[i].x < CH[0].x)){
            swap(CH[0], CH[i]);
        }
    }
    
    sort(CH+1, CH+N, compare);
    
    // 시작점으로 돌아올 때 직선에 점이 여러개인 경우
    // 본래와 다르게 반대로 x, y좌표가 점점 작아지도록 순서를 거꾸로 바꿔줘야 함

    // 처음과 마지막에서 180도가 안나올때까지 idx 내리기
	int idx = N-1;
    while(ccw(CH[0], CH[idx], CH[idx - 1])==0){
        idx--;
    }
	reverse(CH+idx, CH+N);

	for(int i=0; i<N; i++){
		cout << CH[i].idx << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int c;
    cin >> c;
    while(c--) solve();

    return 0;
}