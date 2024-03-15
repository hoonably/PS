#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

int parent[51];
vector<int> party[50];
int num;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    // 작은 값으로 union
    if (a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    int knows;
    cin >> knows;

    for (int i=1; i<=N; i++){
        parent[i]=i;
    }

    for (int i=0; i<knows; i++){
        cin >> num;
        parent[num]=0;  // 아는 사람의 parent = 0
    }

    // 파티를 통해 끝까지 진실을 모르는 사람과 아는 사람 나누기
    // 아는 사람은 0, 모르는 사람은 다른것
    for (int i=0; i<M; i++){
        int people;
        cin >> people;
        for (int j=0; j<people; j++){
            cin >> num;
            party[i].push_back(num);
        }
        for (int j=1; j<people; j++){
            unionParent(party[i][j-1], party[i][j]);
        }
    }

    // 다시 파티에서 하나라도 Parent가 0이면 거짓말 못하는걸로
    int ans = M;
    for (int i=0; i<M; i++){
        for (int person : party[i]){
            if (findParent(person)==0){
                ans--;
                break;
            }
        }
    }

    cout << ans;

    
    return 0;
}