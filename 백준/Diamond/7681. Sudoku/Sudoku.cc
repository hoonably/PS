#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------
Knuth's Algorithm X(크누스 X)

문제를 "집합의 exact cover를 찾는 문제"로 바꿔서 
dancing link 기법을 쓰는 조금 접근방법이 다른 백트래킹 기법
*/


struct node {
	int row;
	int size;
	node* column;
	node* up;
	node* down;
	node* left;
	node* right;
};

void dlx_cover(node* c) {
	c->right->left = c->left;
	c->left->right = c->right;
	for (node* it = c->down; it != c; it = it->down) {
		for (node* jt = it->right; jt != it; jt = jt->right) {
			jt->down->up = jt->up;
			jt->up->down = jt->down;
			jt->column->size--;
		}
	}
}

void dlx_uncover(node* c) {
	for (node* it = c->up; it != c; it = it->up) {
		for (node* jt = it->left; jt != it; jt = jt->left) {
			jt->down->up = jt;
			jt->up->down = jt;
			jt->column->size++;
		}
	}
	c->right->left = c;
	c->left->right = c;
}

bool dlx_search(node* head, int k, vector<int>& solution) {
	if (head->right == head) return 1;
	node* ptr = nullptr;
	int low = 1 << 30;
	for (node* it = head->right; it != head; it = it->right) {
		if (it->size < low) {
			if (it->size == 0) return 0;
			low = it->size;
			ptr = it;
		}
	}
	dlx_cover(ptr);
	for (node* it = ptr->down; it != ptr; it = it->down) {
		solution.push_back(it->row);
		for (node* jt = it->right; jt != it; jt = jt->right) {
			dlx_cover(jt->column);
		}
		if (dlx_search(head, k + 1, solution)) return 1;
		else {
			solution.pop_back();
			for (node* jt = it->left; jt != it; jt = jt->left) {
				dlx_uncover(jt->column);
			}
		}
	}
	dlx_uncover(ptr);
	return 0;
}

vector<int> dlx_solve(vector<vector<int>> matrix) {
	int n = matrix[0].size();
	vector<node> column(n);
	node head;
	head.right = &column[0];
	head.left = &column[n - 1];
	for (int i = 0; i < n; ++i) {
		column[i].size = 0;
		column[i].up = &column[i];
		column[i].down = &column[i];
		if (i == 0) column[i].left = &head;
		else column[i].left = &column[i - 1];
		if (i == n - 1) column[i].right = &head;
		else column[i].right = &column[i + 1];
	}

	vector<node*> nodes;
	for (int i = 0; i < matrix.size(); ++i) {
		node* last = nullptr;
		for (int j = 0; j < n; ++j) if (matrix[i][j]) {
			node* now = new node;
			now->row = i;
			now->column = &column[j];
			now->up = column[j].up;
			now->down = &column[j];
			if (last) {
				now->left = last;
				now->right = last->right;
				last->right->left = now;
				last->right = now;
			}
			else {
				now->left = now;
				now->right = now;
			}
			column[j].up->down = now;
			column[j].up = now;
			column[j].size++;
			last = now;
			nodes.push_back(now);
		}
	}
	
	vector<int> solution;
	dlx_search(&head, 0, solution);
	for (node* ptr: nodes) delete ptr;

	return solution;
}

void solve(string str){
	vector<vector<int>> mat;
	vector<tiii> data;
	char board[9][9];
    int idx = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
            board[i][j] = str[idx++];
            // 0~8까지의 숫자로 변환
			if (board[i][j] != '.') {
				int k = board[i][j] -'1';
				vector<int> row(324, 0);
				row[i * 9 + j] = 1;
				row[81 + i * 9 + k] = 1;
				row[81 * 2 + j * 9 + k] = 1;
				row[81 * 3 + (i / 3 * 3 + j / 3) * 9 + k] = 1;
				mat.push_back(row);
				data.push_back(tiii(i, j, k));
			}
            // .은 아직 채워지지 않은 칸
			else {
				for (int k = 0; k < 9; ++k) {
					vector<int> row(324, 0);
					row[i * 9 + j] = 1;
					row[81 + i * 9 + k] = 1;
					row[81 * 2 + j * 9 + k] = 1;
					row[81 * 3 + (i / 3 * 3 + j / 3) * 9 + k] = 1;
					mat.push_back(row);
					data.push_back(tiii(i, j, k));
				}
			}
		}
	}

	vector<int> ans = dlx_solve(mat);

    // 변화한 부분들 board에 적용
	for (int u: ans) board[get<0>(data[u])][get<1>(data[u])] = get<2>(data[u]);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) cout << board[i][j] + 1;
	}
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    while(true){
        string str;
        cin >> str;
        if(str == "end") break;
        solve(str);
    }


}