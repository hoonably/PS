#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
'A' = 65 , 'Z' = 90 총 26개
비어있는 칸은 0를 사용하자.
각 문자들의 개수를 map으로 표현한다.
*/

int N;
string word;
string charNum[10];
map<char,int> cnt;

// pair의 second (count한 값)이 큰 순서대로 정렬
bool compare(pair<char,int> a, pair<char,int> b) {
	return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (char i = 'A'; i<='Z'; i++){
        cnt[i]=0;
    }
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> word;
        // 빈 공간 '0'으로 할당
        for (int j=0; j<8-word.length(); j++){
            charNum[i] += '0';
        }
        charNum[i] += word;
    }

    // 자리수 정렬을 위한 temp
    int temp = 1e7;
    for (int i=0; i<8; i++){
        for (int j=0; j<N; j++){
            cnt[charNum[j][i]] += temp;
        }
        temp /= 10;
    }

    // map에서 0 삭제
    cnt.erase('0');

    // 정렬을 위해 map을 vector로 변경
    vector<pair<char, int>> vec(cnt.begin(), cnt.end());
    sort(vec.begin(), vec.end(), compare);
    

    // 계산을 위한 새로운 map 
    map<char,int> changeInt = {{'0',0}};

    // 정렬로 순위가 가장 높은것부터 10개를 9,8,7,6 순으로 넣기
    for (int i=0; i<10; i++){
        changeInt[vec[i].first] = 9-i;
    }

    // 계산하기
    int ans = 0;
    temp = 1e7;
    for (int i=0; i<8; i++){
        for (int j=0; j<N; j++){
            ans += temp * changeInt[charNum[j][i]];
        }
        temp /= 10;
    }
    cout << ans;
    
    return 0;
}