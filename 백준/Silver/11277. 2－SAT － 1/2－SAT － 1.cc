	#include <cstdio>
#include <vector>
using namespace std;
 
int n, m, ans;
vector<pair<int, int>> v;
vector<bool> state;
 
void dfs(int depth) {
 
	if (depth == n + 1) {
 
		bool chk = true;
		for (int i = 1; i < v.size(); ++i)
		{
			bool l, r;
			if (v[i].first < 0)
			{
				l = !state[-v[i].first];
			}
			else
			{
				l = state[v[i].first];
			}
 
			if (v[i].second < 0) {
 
				r = !state[-v[i].second];
			}
			else
			{
				r = state[v[i].second];
			}
 
			if (l == false && r == false)
				chk = false;
 
 
		}
		if (chk) 
			ans = 1;
		
 
		return;
	}
 
	for (int i = 0; i < 2; ++i) {
		if (i == 0) {
			state[depth] = true;
		}
		else {
			state[depth] = false;
		}
		dfs(depth + 1);
	}
}
 
int main()
{
	scanf("%d %d", &n, &m);
	v.resize(m + 1);
	state.resize(n + 1, true);
 
	for (int i = 1; i <= m; ++i)
		scanf("%d %d", &v[i].first, &v[i].second);
 
	dfs(1);
 
	printf("%d", ans);
 
	return 0;
}