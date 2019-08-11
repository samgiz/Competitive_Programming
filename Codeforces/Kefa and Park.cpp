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

bool A[N];
vector<int>E[N];

int ans = 0;
int n, m;
void count(int cur, int cats, int par){
	if(A[cur]==0)cats=0;
	else cats++;
	if(cats>m)return;
	if(E[cur].size()==1&&cur!=1)ans++;
	for(auto i: E[cur]){
		if(i!=par)count(i, cats, cur);
	}
}

int main(){
	// fastInputOutput;
	
	cin>>n>>m;
	forii(1, n+1)cin>>A[i];
	fori(n-1){
		int a, b;
		cin>>a>>b;
		E[a].pb(b);
		E[b].pb(a);
	}

	count(1, 0, 0);

	cout<<ans;
}
