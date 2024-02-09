#include <iostream>
using namespace std;

// 1. while 조건에 getline 함수 리턴값 이용
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string str;
    while(getline(cin, str)){
        cout << str << '\n';
    }
}


// 2. break문 사용
// int main(){ 
//     string str;
//     while (true){
//         getline(cin, str);
//         if (str=="")
//             break;
//         cout << str << endl;
//     } 
//     return 0;
// }