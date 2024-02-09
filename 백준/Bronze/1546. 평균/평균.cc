#include <iostream>
using namespace std;

int main(void){
    int scores[1001];
    int N, get_num, max=0;
    float sum=0;
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> get_num;
        scores[i] = get_num;
        sum += get_num;
        if (get_num>max){
            max = get_num;
        }
    }
    sum = sum / max * 100;
    cout << sum / N;
    return 0;
}