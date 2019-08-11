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

map<pll, ll>M;

int main(){
	// fastInputOutput;
	int q;
	cin>>q;
	fori(q){
		ll t, v, u;
		cin>>t>>v>>u;
		if(t==1){
			ll w;
			cin>>w;
			while(v!=u){
				if(v>u)M[mp(v/2, v)]+=w, v/=2;
				else M[mp(u/2, u)]+=w, u/=2;
			}
		}
		else{
			ll ans = 0;
			while(v!=u){
				if(v>u)ans+=M[mp(v/2, v)], v/=2;
				else ans+=M[mp(u/2, u)], u/=2;
			}
			cout<<ans<<endl;
		}
	}
}
