#include <bits/stdc++.h>
using namespace std;

int cntX[10], cntY[10];

string solution(string X, string Y) {
    for(char c : X) cntX[c-'0']++;
    for(char c : Y) cntY[c-'0']++;
    
    string answer = "";
    for(int i=9; i>=0; i--){
        int cnt = min(cntX[i], cntY[i]);
        for(int j=0; j<cnt; j++) answer += (char)(i+'0');
    }
    
    if (answer[0]=='0') answer = "0";  // 0이 여러개
    else if (answer=="") answer = "-1";  // 아무것도 
    return answer;
}