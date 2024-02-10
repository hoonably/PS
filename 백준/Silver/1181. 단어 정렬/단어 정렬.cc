#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 비교 함수
bool compare(const string& a, const string& b) {

    // a의 길이가 더 짧다면 true 반환
    if (a.length() < b.length()) return true;
    // a의 길이가 더 길다면 false 반환 
    else if(a.length() > b.length()) return false;

    // 단어 길이가 같다면 원래 정렬대로 정렬
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> words;
    
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    
    // 내가 만든 compare 함수를 기준으로 정렬
    sort(words.begin(), words.end(), compare);
    
    for (int i = 0; i < words.size(); ++i) {
        // 중복 무시
        if (i > 0 && words[i] == words[i - 1]) continue;
        cout << words[i] << "\n";
    }
    
}