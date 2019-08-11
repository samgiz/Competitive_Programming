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
	map<int, int>M;
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a;
		M[a]++;
	}
	if(M.size()!=2){cout<<"NO";exit(0);}
	vector<pair<int, int>>P;
	for(auto i : M){
		P.pb(i);
	}
	if(P[0].se!=P[1].se)cout<<"NO";
	else cout<<"YES"<<endl<<P[0].fi<<" "<<P[1].fi;
	cerr<<endl;
}