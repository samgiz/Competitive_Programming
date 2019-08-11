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

vi E[50001];
ll DP[50001][501];

ll ans = 0;
int n, k;

void DFS(int cur, int par){
	DP[cur][0]=1;
	for(auto i: E[cur]){
		if(i==par)continue;
		DFS(i, cur);
		forj(k)DP[cur][j+1]+=DP[i][j];
	}
	ans+=2*DP[cur][k];
	for(auto i: E[cur]){
		if(i==par)continue;
		forjj(1, k)ans+=DP[i][j-1]*(DP[cur][k-j]-DP[i][k-j-1]);
	}
}

int main(){
	fastInputOutput;
	cin>>n>>k;
	fori(n-1){
		int u, v;
		cin>>u>>v;
		E[u].pb(v);
		E[v].pb(u);
	}
	DFS(1, 0);
	ans/=2;
	cout<<ans;
}
