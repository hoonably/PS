#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    string str;
    cin>>str;
    // char 기준으로 내림차순 정렬
    sort(str.begin(), str.end(), greater<char>());
    cout<<str;
}