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

vi Good[N], Bad[N];
vi Ans;
int ans = 0;

bool recurse(int cur, int par, bool bad){
	bool fixed = 0;
	for(auto i: Good[cur]){
		if(i==par)continue;
		fixed|=recurse(i, cur, 0);
	}
	for(auto i: Bad[cur]){
		if(i==par)continue;
		fixed|=recurse(i, cur, 1);
	}

	if(!fixed&&bad)ans++, Ans.pb(cur);
	fixed|=bad;
	return fixed;
}

int main(){
	// fastInputOutput;
	int n;
	cin>>n;
	fori(n-1){
		int u, v, t;
		cin>>u>>v>>t;
		if(t==1){
			Good[u].pb(v);
			Good[v].pb(u);
		}
		else{
			Bad[u].pb(v);
			Bad[v].pb(u);
		}
	}
	recurse(1, 0, 0);
	cout<<ans<<endl;
	for(auto i: Ans)cout<<i<<" ";
}
