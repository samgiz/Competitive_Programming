#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	set<char> S;
	int M=0;
	for(int i=0; i<n; i++){
		if(s[i]>='a'&&s[i]<='z'){
			S.insert(s[i]);
		}
		else{
			M=max((int)S.size(), M);
			S.clear();
		}
	}
	cout<<max(M, (int)S.size());
	cerr<<endl;
}