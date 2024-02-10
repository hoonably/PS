#include <iostream>
using namespace std;

// 카운팅정렬 (수의 범위가 작음)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int n;
    int arr[10001] = {0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
        int get_num;
        cin >> get_num;
        arr[get_num]++;
	}

    for (int i = 1; i <= 10000; i++) {
        for (int j=0; j<arr[i]; j++){
            cout << i << '\n';
        }
	}

    return 0;
}