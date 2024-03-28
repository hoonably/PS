#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
행렬을 그대로 저장하지 말고 새로 저장
*/

int graph[50][50];

void change(int x, int y){
    FOR(i, x, x+2){
        FOR(j, y, y+2){
            graph[i][j]^=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    FOR(i,0,N-1){
        FOR(j,0,M-1){
            char c;
            cin >> c;
            graph[i][j] = c-'0';
        }
    }

    FOR(i,0,N-1){
        FOR(j,0,M-1){
            char c;
            cin >> c;
            graph[i][j] ^= c-'0';  // xor 연산으로 다르면 1
        }
    }

    int cnt = 0;
    FOR(i,0,N-3){
        FOR(j,0,M-3){
            if (graph[i][j]) {
                change(i,j);
                cnt++;
            }
        }
    }

    FOR(i,0,N-1){
        FOR(j,0,M-1){
            if(graph[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}