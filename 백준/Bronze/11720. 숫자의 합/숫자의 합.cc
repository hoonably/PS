#include <iostream>
using namespace std;

int main(void){
    int N, sum=0;
    string num;
    cin >> N;
    cin >> num;
    for (int i=0;i<N;i++){
        sum += num[i]-'0';
    }
    cout << sum;
    return 0;
}