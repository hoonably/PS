#include <iostream>
#include <string>
using namespace std;

int main(void){
    int num1;
    string num2;
    cin >> num1;
    cin >> num2;

    cout << num1 * (num2[2]-'0') << endl;
    cout << num1 * (num2[1]-'0') << endl;
    cout << num1 * (num2[0]-'0') << endl;

    // string -> int변환 
    // include <string>
    // stoi() 함수 사용
    cout << num1 * stoi(num2) << endl;
    return 0;
}