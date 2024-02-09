#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string line[5];
    for (int i=0; i<5; i++){
        cin >> line[i];
    }
    for (int i=0; i<15; i++){
        for (int j=0; j<5; j++){
            // 이거 안해주면 마지막에 '\0'을 출력하므로 틀림
            if (i < line[j].size()){
                cout << line[j][i];
            }
        }
    }
    return 0;
}