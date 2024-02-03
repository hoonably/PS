// 인접한 두 원소를 검사하여 순서가 맞지 않으면 교환
// 시간 복잡도 : 최선 O(N^2) / 평균 O(N^2) / 최악 O(N^2)

#include <iostream>
using namespace std;

int arr[1000];

void bubble_sort(int *arr, int n){
    int i, j, temp;

    for (i=n-1; i>0; i--) {
        for (j=0; j<i; j++) {
            if (arr[j]>arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}

int main(void){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}