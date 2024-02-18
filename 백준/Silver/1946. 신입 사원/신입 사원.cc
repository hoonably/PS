#include <bits/stdc++.h>
using namespace std;

/*

*/

int T, N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	cin >> T;
	while(T--){

		cin >> N;
		vector<pair<int,int>> v;

		for(int i=0; i<N; i++){
			int a,b;
			cin >> a >> b;
			v.push_back({a,b});
		}
		sort(v.begin(), v.end());
		
		int tmp = 0;
		int ans = 1;
		for(int i=1; i<N; i++){
			if(v[tmp].second > v[i].second){
				ans++;
				tmp = i;  // 탐색했던거로 다음 타겟 변경
			}
		}
		cout << ans << '\n';
	}
    
    return 0;
}