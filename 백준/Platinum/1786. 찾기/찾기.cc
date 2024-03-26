#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

string s,t;
int lps[1000010];
vector<int> v;

// 접두사와 접미사가 일치하는 가장 긴 길이 저장
void makeLps(){
    int len=0;
    for(int i=1;i<t.length();i++){
        while(len>0 && t[i]!=t[len]){
            len=lps[len-1];
        }
        if(t[i]==t[len]) lps[i]=++len;
    }
}

void kmp() {
    int j=0;
    for(int i=0;i<s.length();i++){
        while(j>0 && s[i]!=t[j])
            j = lps[j-1];
        if(s[i] == t[j]){
            if(j==t.length()-1){
                // cout << i << '\n';
                v.push_back(i-t.length()+1);
                j = lps[j];
            }
            else j++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    getline(cin,s);
    getline(cin,t);
    makeLps();
    kmp();

    cout<<v.size()<<'\n';

    for (auto i:v) {
        cout << i+1 << ' ';
    }
    return 0;
}