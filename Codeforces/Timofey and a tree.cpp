#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops
#define fori(a) for(def i=0; i<(a); i++)
#define forii(a, b) for(def i=(a); i<(b); i++)
#define forj(a) for(def j=0; j<(a); j++)
#define forjj(a, b) for(def j=(a); j<(b); j++)
#define fork(a) for(def k=0; k<(a); k++)
#define forkk(a, b) for(def k=(a); k<(b); k++)
#define fore(a) for(def e=0; e<(a); e++)
#define foree(a, b) for(def e=(a); e<(b); e++)
#define forl(a) for(def l=0; l<(a); l++)
#define forll(a, b) for(def l=(a); l<(b); l++)

#define fastInputOutput ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int N = 100001;

vector<int> E[N];
int C[N];

bool annoys(int cur, int par, int color){
	if(C[cur]!=color)return 1;
	for(auto i: E[cur]){
		if(par==i)continue;
		if(annoys(i, cur, color))return 1;
	}
	return 0;
}

int main(){
	// fastInputOutput;
	int n;
	cin>>n;
	int a=-1, b=-1;
	fori(n-1){
		int u, v;
		cin>>u>>v;
		E[u].pb(v);
		E[v].pb(u);
	}
	forii(1, n+1)cin>>C[i];
	forii(1, n+1){
		for(auto j: E[i]){
			if(C[i]!=C[j])a=i, b=j;
		}
	}
	if(a==-1)cout<<"YES"<<endl<<1;
	else{
		bool lg=true;
		for(auto i: E[a])lg = lg & (!annoys(i, a, C[i]));
		if(lg){cout<<"YES"<<endl<<a;exit(0);}
		lg=true;
		for(auto i: E[b])lg = lg & (!annoys(i, b, C[i]));
		if(lg){cout<<"YES"<<endl<<b;exit(0);}
		cout<<"NO";
	}
}
