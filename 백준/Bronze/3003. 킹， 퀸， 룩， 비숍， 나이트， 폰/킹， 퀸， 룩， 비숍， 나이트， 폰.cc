#include <iostream>
using namespace std;

int main(){
    int chess[] = {1,1,2,2,2,8};
    for (int i=0;i<6;i++){
        int temp;
        cin >> temp;
        chess[i]-=temp;
    }
    for (int i=0; i<6; i++){
        cout << chess[i] << ' ';
    }
    return 0;
}