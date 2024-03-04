#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


string line;
int n;

int main(){
	cin>>n;
	int pre_R = 0;
	int pre_B = 0;
	int R,B;
	for(int i=0;i<n;i++){
		cin>>line;
		R = -2*pre_R;
		
		B = -pre_B/2;
		for(char c : line)
			if(c == 'B') B++;
			else R++;
			
		if(R < 0 || B < 0 || B%2){
			cout<<0;
			return 0;
		}
		pre_R = R;
		pre_B = B;
		
	}
	if(R==0 && B == 0) cout<<1;
	else cout<<0;
	return 0;
}