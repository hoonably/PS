#include <iostream>
using namespace std;

int main(void){
    int N, get_num, max, min;
    scanf("%d", &N);

    cin >> get_num;
    max = min = get_num;

    for (int i=0; i<N-1; i++){
        cin >> get_num;
        if (get_num<min){
            min = get_num;
        }
        else if (get_num>max){
            max = get_num;
        }
    }
    cout << min << ' ' << max;

    return 0;
}