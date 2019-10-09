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
#define N 500001

vi T[N];
vpii A;

int Par[N], Comps[N], Siz[N];

map<pii, bool> Lg;

void DFS(int cur, int par){
	Par[cur] = par;
	Siz[par]++;
	for(auto &i : T[cur]){
		if(Par[i] == -1){
			DFS(i, par);
		}
	}
}

int main(){
	fastInputOutput;
	int n, m;
	cin>>n>>m;
	fori(n+1) Par[i]=-1; 
	int a, b;
	char c;

	fori(m){
		cin>>a>>b>>c;
		if(c == 'A')
			A.pb(mp(a, b));

		else{
			T[a].pb(b);
			T[b].pb(a);
		}
	}
	int cnt = 0;
	forii(1, n+1){
		if(Par[i]==-1){
			cnt++;
			DFS(i, i);
		}
	}

	for(auto &i: A){
		int a = Par[i.fi];
		int b = Par[i.se];
		if(a!=b && Lg[mp(a, b)] == 0){
			Comps[a]++;
			Comps[b]++;
			Lg[mp(a, b)]=1;
			Lg[mp(b, a)]=1;
		}
	}

	int ans = 0;
	forii(1, n+1){
		if(Par[i]==i && Comps[i] == cnt-1)
			ans += Siz[i];
	}
	cout<<ans;
}
