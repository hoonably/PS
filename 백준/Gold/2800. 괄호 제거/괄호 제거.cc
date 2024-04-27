#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
괄호의 위치 인덱스를 저장
괄호를 닫을 때 그 괄호와 쌍인 여는 괄호의 인덱스를 pair로 저장
*/

string str;
int len;
vector<pii> idxPair;
bool visited[10];
int pairCnt;

bool cmp(pii a, pii b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> str;
    len = str.length();

    stack<int> st;
    for (int i=0; i<len; i++){
        if (str[i]=='(') st.push(i);
        else if (str[i]==')'){
            pairCnt++;
            idxPair.push_back({st.top(), i});
            st.pop();
        }
    }
    sort(idxPair.begin(), idxPair.end(),cmp);


    // 비트마스킹 조합 
	vector<string> ans;

    // 하나라도 제거해야하므로 1부터 시작
	for (int i = 1; i < (1 << pairCnt); i++) {
		string tmp = str;

        // 문자 제거
		for (int j = 0; j < pairCnt; j++) {
			if (i & (1 << j)) {
				auto [a,b] = idxPair[j];
				tmp[a] = '.';
				tmp[b] = '.';
			}
		}

		tmp.erase(remove(tmp.begin(), tmp.end(), '.'), tmp.end());
		ans.emplace_back(tmp);
	}
	sort(ans.begin(), ans.end()); 
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (string answer : ans)
		cout << answer << "\n";
    
    return 0;
}