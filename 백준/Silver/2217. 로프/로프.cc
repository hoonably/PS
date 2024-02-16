#include <bits/stdc++.h>
using namespace std;

/*
로프를 일단 정렬한 후
버틸 수 있는 무게가 가장 큰거부터 걸고, 
계속 순서대로 걸어나가면서 최대 중량을 올리고,

최대중량 : 가장 약한 로프 * 총 로프 수
        : rope[i] * i

4

3
3
3
10

입력시 3이 세개이므로 바로 break하면 틀림
12가 정답임
*/

int N;
double rope[100001];

bool compare(int a, int b) {
	return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> rope[i];
    }

    sort(rope+1, rope+N+1, compare);

    double best = 0;
    for (int i=1; i<=N; i++){
        best = max(best, *(rope+i) * i);
    }
    cout << (int)best;

    return 0;
}