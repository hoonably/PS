#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
최적화 1
branchCut[i] : 가지치기로 i번째 레벨에서 최대값 만드는게 불가능한지 판단
branchCut[3]=16 이었는데 지금 3레벨 상태에서 최대값이 8이라면 
새로운 최대값을 만들기 불가능하니까 바로 종료

최적화 2
이동했을때 변화가 없다면 계속 가지 않는다.

99%에서 계속 틀린 이유
: 보드의 크기가 1이면 같을수밖에 없어서 same 에서 걸린다. 
예외처리를 해준다.
*/

int N;
int graph[20][20];
int ans;
int branchCut[10];

// 4방향을 모두 구현하기엔 함수가 4개가 필요하기 때문에
// 90도로 회전시키는 함수 이용
void rotate(int arr[][20], int newArr[][20]) { // cw
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            newArr[j][N-1-i] = arr[i][j];
        }
    }
}

bool pushleft(int arr[][20]) { // left push
    bool changed = false;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (arr[i][j]) {
                int tmpj = j;
                while (tmpj && !arr[i][tmpj-1]) {
                    changed = true;
                    swap(arr[i][tmpj-1], arr[i][tmpj]);
                    tmpj--;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            // merge
            if (arr[i][j] && arr[i][j+1] && arr[i][j] == arr[i][j+1]) {
                changed = true;
                arr[i][j] *= 2;
                arr[i][j+1] = 0;
                int tmpj = j+1;
                while (tmpj < N-1) {
                    swap(arr[i][tmpj], arr[i][tmpj+1]);
                    tmpj++;
                }
            }
        }
    }
    return changed;
}

void backtracking(int level, int arr[][20]){

    // branchCut을 위한 최대값 찾기
    int maxValue = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            maxValue = max(maxValue, arr[i][j]);
        }
    }

    if (level==5) {
        if (maxValue > ans){
            ans = maxValue;
            // 최대값이 갱신되었다면 branchCut 생성
            for (int i=4; i>=0; i--){
                maxValue /= 2;
                branchCut[i] = maxValue;
            }
        }
        return;
    }

    // branchCut (최대값 만드는게 불가능)
    if (maxValue < branchCut[level]) return;

    // 4번 도는 임시배열
    int temp[4][20][20];
    rotate(arr, temp[0]);
    for (int i = 1; i < 4; i++) {
        rotate(temp[i-1], temp[i]);
    }    
    for (int i = 0; i < 4; i++) {

        // 최적화 2
        // 이동했을때 변화가 없다면 계속 가지 않는다.
        if (pushleft(temp[i])) {
            backtracking(level+1, temp[i]);            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> graph[i][j];
        }
    }

    if (N==1) {
        cout << graph[0][0];
        exit(0);
    }

    backtracking(0, graph);

    cout << ans;
    
    return 0;
}