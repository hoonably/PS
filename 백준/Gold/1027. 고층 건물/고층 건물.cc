#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
정수를 정수로 나누면 정수가 나와 소수점 이하가 사라집니다. 
1.0* 을 식 앞에 써주세요. (예시 : double x = 1.0*a/b;)
*/

int H[50], see[50];
double angle;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    for (int i=0; i<N; i++){
        // 앞에 탐색 (기울기)
        angle = 1e9;  // 최대값으로 설정
        for (int j=i-1; j>=0; j--){
            // 정수를 정수로 나누면 정수가 나와 소수점 이하가 사라짐.
            // 1.0을 먼저 곱해 double임을 나타내자.
            double new_angle = 1.0 * (H[i]-H[j]) / (i-j);  
            if (new_angle < angle){
                angle = new_angle;
                see[i]++;
            }
        }
        // 뒤에 탐색 (기울기)
        angle = -1e9;  // 최소값으로 설정
        for (int j=i+1; j<N; j++){
            double new_angle = 1.0 * (H[i]-H[j]) / (i-j);
            if (new_angle>angle){
                
                angle = new_angle;
                see[i]++;
            }
        }
    }
    cout << *max_element(see, see+N);
    
    return 0;
}