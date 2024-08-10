#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<pair<bool, string>> temp; // true면 입장, false면 퇴장, string은 id
    map<string, string> nick;  // id에 따른 닉네임
    string status, userID, nickname;

    for (string line : record){
        // istringstream으로 이미 있는 string 자르기
        istringstream l (line);
        
        getline(l, status, ' ');
        getline(l, userID, ' ');
        
        if (status[0]=='E') {
            getline(l, nickname, ' ');
            nick[userID] = nickname;
            temp.push_back({true, userID});
        } // 채팅방에 들어옴

        else if (status[0]=='L') {
            temp.push_back({false, userID});
        } // 채팅방을 나감

        else {
            getline(l, nickname, ' ');
            nick[userID] = nickname;
        } // 이름을 바꿈
    }

    vector<string> answer;
    for (auto t : temp){
        nickname = nick[t.second];
        if (t.first == true){  // 입장
            answer.emplace_back(nickname + "님이 들어왔습니다.");
        }
        else {  // 퇴장
            answer.emplace_back(nickname + "님이 나갔습니다.");
        }
    }
    
    return answer;
}