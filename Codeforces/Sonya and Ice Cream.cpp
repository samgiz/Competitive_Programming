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
map<ll, ll> E[N];
ll Max[N];

int main(){
	// fastInputOutput;
	ll n, k;
	cin>>n>>k;
	fori(n-1){
		ll u, v, d;
		cin>>u>>v>>d;
		E[u][v]=d;
		E[v].insert(mp(u, d));
	}
	priority_queue<pll, vpll, greater<pll> > Q;
	ll ct = n;
	forii(1, n+1){
		if(E[i].size()==1){
			ll el = (*(E[i].begin())).se;
			Q.push(mp(Max[i]+el, i));
		}
	}
	while(ct>k||Q.size()>2){
		// cost so far, original leaf
		auto p = Q.top();
		// cerr<<p.se<<" "<<p.fi<<endl;
		Q.pop();
		// new leaf
		ll el = (*(E[p.se].begin())).fi;
		// new leaf possibly 
		E[el].erase(p.se);
		Max[el] = max(Max[el], p.fi);
		if(E[el].size()==1){
			ll el1 = (*(E[el].begin())).se;
			Q.push(mp(Max[el]+el1, el));
		}
		ct--;
	}
	ll ans = 0;
	forii(1, n+1)ans = max(ans, Max[i]);
	cout<<ans;
	// cerr<<endl<<ct;
}
