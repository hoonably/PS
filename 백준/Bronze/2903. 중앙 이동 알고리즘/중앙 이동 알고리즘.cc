#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    // 2 3 5 9
    int line = pow(2, N)+1;
    cout << (int)pow(line,2);
    
    return 0;
}