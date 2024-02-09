#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int A, B;
    for (int i=0; i<N; i++){
        cin >> A >> B;
        cout << A+B << endl;
    }
    return 0;
}