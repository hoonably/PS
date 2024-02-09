#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    char num_list_1[4], num_list_2[4];
    int num1, num2;
    cin >> num_list_1 >> num_list_2;
    swap(num_list_1, num_list_1+2);
    swap(num_list_2, num_list_2+2);

    num1 = stoi(num_list_1);
    num2 = stoi(num_list_2);

    if (num1>=num2){
        cout << num1;
    }
    else{
        cout << num2;
    }
    return 0;
}