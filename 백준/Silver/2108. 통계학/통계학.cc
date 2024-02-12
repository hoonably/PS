#include <bits/stdc++.h>
using namespace std;

int avg(vector<int> list){
    double res = 0;
    for (int num : list){
        res += num;
    }
    return round(res / list.size());
}

int median(const vector<int>& list) {
    // 정렬이 되어있다는 가정 하에
    return list[list.size() / 2];
}

vector<int> mode(vector<int> list) {
    vector<int> modes;
    int cnt = 1;  // 현재 최빈값의 개수
    int temp = 1;  // 현재 진행중인 연속상태

    list.push_back(10000);  // 마지막까지 확인을 위해 임시로 넣어주기

    for (int i=1; i<list.size(); i++){
        if (list[i]==list[i-1]){  // 이전꺼랑 같다면
            temp++;
        }
        else if (temp > cnt){  // 연속 끊겼는데 최고기록을 넘었다면
            modes = {list[i-1]};
            cnt = temp;
            temp = 1;
        }
        else if (temp == cnt){  // 연속 끊겼는데 최고기록과 동일하다면
            modes.push_back(list[i-1]);
            temp = 1;
        }
        else temp = 1;  // 연속 끊겼는데 기록 못깼다면
    }
    return modes;
}

int list_range(const std::vector<int>& list) {
    return list.back() - list.front();
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, get_num;
    vector<int> nums;

    cin >> N;
    while(N--){
        cin >> get_num;
        nums.push_back(get_num);
    }
    sort(nums.begin(), nums.end());

    // 1. 평균
    cout << avg(nums) << '\n';
    // 2. 중앙값
    cout << median(nums) << '\n';

    // 3. 최빈값
    vector<int> modes = mode(nums);
    if (modes.size()==1) cout << modes[0] << '\n';
    else cout << modes[1] << '\n';

    // 4. 범위
    cout << list_range(nums) << '\n';

    
    return 0;
}