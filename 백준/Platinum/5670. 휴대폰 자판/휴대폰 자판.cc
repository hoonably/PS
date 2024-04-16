#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
트라이 자료구조
다음 자식의 개수가 1개라면 자동으로 입력된다.
EOF 문제 Ctrl + Z + Enter 입력
*/

struct Trie {
	Trie *child[26];  // 소문자 개수 26
    int cntChild;  // 자식의 개수
    bool finish;  // 끝나는 여부

    // 생성자
    Trie() {
		fill(child, child+26, nullptr);  // child 초기화
        cntChild = 0;
        finish=false;
	}

    // 소멸자
    ~Trie() {
        for(int i=0;i<26;i++) delete child[i];
    }
	
	void insert(char *str) {
        // 문자열이 끝났다면
		if(*str=='\0') {
            finish = true;
			return;
		}
		int cur = *str-'a';
		if(child[cur] == nullptr) {
            child[cur] = new Trie();
            cntChild++;
        }
		child[cur]->insert(str+1);  // 다음 문자열 포인터로
	}
	
    // 자동으로 입력되지 않는 것의 개수 return
	int countNotAuto(char *str, int cnt) {

		// 마지막 문자열이라면 cnt 반환
		if(*str=='\0') {
            return cnt;
		}

        int cur = *str-'a';

        // 조심할 점
        // hello 와 hell 이 있다면
        // hello는 hell 보다 한번 더 쳐야 하므로
        // hell 에서 끝나는게 있으면 1 카운트를 해야한다.

        // 자식이 한개면서 거기서 끝나는게 없다면 입력 안해도 됨
        if (cntChild==1 && !finish) return child[cur]->countNotAuto(str+1, cnt);
		
        // 자식이 여러개라면 직접 입력해야하므로 1 카운트
		return child[cur]->countNotAuto(str+1, cnt+1);
	}
};

int N;

double solve(){
    int sum = 0;
    Trie *root = new Trie();

    // 주의할 점 : 1번째 글자는 무조건 직접 입력해야함 (첫번째 글자가 모두 같더라도)
    // 그래서 root로만 이루어진것을 있다고 친다. => 무조건 첫번째에 카운트됨
    root->finish = true;


	// string 말고 char 배열로 받기
	// 글자수는 최대 80 + '/0' 생각해서 1 추가
	vector<char[81]> num(N);
    
    for (int i=0; i<N; i++){
        cin >> num[i];
        root->insert(num[i]);
    }


    for(int i=0; i<N; i++) {
        // cout << num[i] << ' ' << root->countNotAuto(*(&num[i]+1),1) << '\n';
        sum += root->countNotAuto(num[i], 0);
    }

    delete root;

    return 1.0 * sum / N;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cout << fixed << setprecision(2);

    while(cin>>N){  //EOF
        cout << solve() << '\n';
    }
    
    return 0;
}