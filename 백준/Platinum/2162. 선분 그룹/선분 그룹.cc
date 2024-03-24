#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 3001

/*
세 점이 일직선에 있는 경우를 생각해줘야한다.

CCW(A, B, C) * CCW(A, B, D) < 0    &&
CCW(C, D, A) * CCW(C, D, B) < 0

점 C, D 는 선분AB의 연장선상 직선을 기준으로 
항상 서로 반대편에 존재하고 

점 A, B는 선분CD의 연장선상 직선을 기준으로 
서로 반대편에 존재함으로써 교점이 존재하는 상태로 판단
*/

struct dot {
    ll x, y;

    void read() {cin >> x >> y;}

    // 연산자 <= 로 x, y 순으로 bool 반환
    bool operator<=(dot const &p1){
        if (x==p1.x){
            return y<=p1.y;
        }
        else return x<=p1.x;
    }
};

struct line {
    dot A, B;
    void read() {cin >> A.x >> A.y >> B.x >> B.y;}
};

line L[MAX];
int parent[MAX];
map<int,int> cnt;  //부모에 따른 원소의 개수

// 부모 노드를 찾는 함수
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    // a==b인 경우 둘이 이미 같은 집합이므로 합치지 않음
    if (a == b) return;

    parent[b] = a;
    cnt[a] += cnt[b];
    cnt.erase(b);  // 합쳐진 하위 집합 없애기
}

int ccw(dot p1, dot p2, dot p3) {
    ll s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;

    if (s > 0) return 1;  // 반시계방향
    else if (s == 0) return 0;  //직선
    else return -1;  // 시계방향
}

bool isOverlapped(dot A, dot B, dot C, dot D) {
    int ans1 = ccw(A, B, C) * ccw(A, B, D); // 선분AB를 기준으로 점 C, 점 D 를 체크하는 부분
    int ans2 = ccw(C, D, A) * ccw(C, D, B); // 선분CD를 기준으로 점 A, 점 B 를 체크하는 부분
    
    // 1. 선분이 일직선인 경우
    if(ans1 == 0 && ans2 == 0){     
        if(B <= A) swap(A, B);  // A, B 정렬
        if(D <= C) swap(D, C);  // C, D 정렬
        
        return A <= D && C <= B;  // 순위가 겹치면 true
    }

    // 2. 한 점에서 교차 (CCW가 방향이 모두 다름)
    if(ans1 <= 0 && ans2 <= 0){
        return true;
    }
    // 3. 교차 안함
    else return false;  //CCW가 같은 방향이 있음
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    for (int i=1; i<=N; i++){
        L[i].read();
        
        parent[i] = i;  // 부모 자신으로
        cnt[i] = 1;  // 집합 개수 1로
    }

    for (int i=1; i<N; i++){
        for (int j=i+1; j<=N; j++){
            if (isOverlapped(L[i].A, L[i].B, L[j].A, L[j].B)){
                unionParent(i, j);
                continue;
            }
        }
    }

    cout << cnt.size() << '\n';
    
    int ans = 0;
    for (auto c : cnt){
        ans = max(ans, c.second);
    }
    cout << ans;
    
    return 0;
}