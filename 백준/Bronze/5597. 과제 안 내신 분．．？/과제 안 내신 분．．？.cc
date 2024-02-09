#include <iostream>
using namespace std;

int main(void){
    int arr[31] = {false};
    int n;
    for (int i=0; i<28; i++){
        cin >> n;
        arr[n]=true;
    }
    for (int i=1; i<31; i++){
        if (!arr[i]){
            cout << i << endl;
        }
    }
    return 0;
}