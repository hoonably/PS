#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
분할 정복을 통해 히스토그램에서 가장 큰 직사각형의 넓이 구하기

밑변의 길이가 1인경우는 바로 높이를 return

왼쪽 넓이 vs 가운데 겹쳐있는 넓이 vs 오른쪽 넓이
셋 중 최대값을 return 하면 된다.

*/

int n;
ll h[100000];

ll maxSquare(int l, int r){
    // 밑변의 길이가 1인 경우 높이 반환
    if (l==r) return h[l];

    int m = (l+r)/2;  // 분할

    // 1. 왼쪽, 오른쪽 반 분할해서 최대값 저장
    ll bestLR = max(maxSquare(l, m),maxSquare(m+1,r));


    // 2. 가운데 선을 걸쳐있는 경우 구하기

    // 가운데에서 왼쪽으로 한칸씩, 오른쪽으로 한칸씩 늘려나갈거임
    int ml = m;
    int mr = m+1;
    int length = 2; // 밑변의 길이
    ll height = min(h[ml], h[mr]);  // 가능한 높이

    // 가운데 선 지나는 최대값 start
    ll bestBetween = length * height;

    // 이제 한칸씩 갈건데, 만약 끝까지 갔거나 0을 만났다면 더 이상 안간다.
    // 양쪽 다 못간다면 탐색을 종료한다.
    bool leftgo;
    bool rightgo;

    while(true){
        // 가려는 곳이 높이가 0이 아니고, 끝까지 간게 아니면 갈 수 있음
        leftgo = (h[ml-1]!=0) && (ml!=l);
        rightgo = (h[mr+1]!=0) && (mr!=r);

        // 양쪽 다 갈 수 있는 경우
        if (leftgo && rightgo) {

            // 왼쪽이 높이가 더 큰 경우
            if (h[ml-1]>=h[mr+1]){
                ml--;
                height = min(height, h[ml]);
            }

            // 오른쪽이 높이가 더 큰 경우
            else {
                mr++;
                height = min(height, h[mr]);
            }
        }
        // 왼쪽만 갈 수 있는 경우
        else if (leftgo){
            ml--;
            height = min(height, h[ml]);
        }
        // 오른쪽만 갈 수 있는 경우
        else if (rightgo){
            mr++;
            height = min(height, h[mr]);
        }
        // 양쪽다 못가는 경우 종료
        else break;

        // 길이 1씩 증가
        length++;
        // 시행때마다 최대값 업데이트
        bestBetween = max(bestBetween, height*length);
    }
    return max(bestLR, bestBetween);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true){
        cin >> n;
        if (n==0) break;
        for (int i=0; i<n; i++){
            cin >> h[i];
        }
        cout << maxSquare(0, n-1) << '\n';
    }
    
    return 0;
}