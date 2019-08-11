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

vi E[N];

bool A[N], B[N];

vi Ans;

int ans = 0;

void flip(int cur, int par, int f1, int f2){
	bool rev=0;
	if((A[cur]^f1)!=B[cur])ans++, rev=1, Ans.pb(cur);
	for(auto i: E[cur]){
		if(i==par)continue;
		flip(i, cur, f2, f1^rev);
	}
}

int main(){
	// fastInputOutput;
	int n;
	cin>>n;
	fori(n-1){
		int u, v;
		cin>>u>>v;
		E[u].pb(v);
		E[v].pb(u);
	}
	forii(1, n+1)cin>>A[i];
	forii(1, n+1)cin>>B[i];

	flip(1, 0, 0, 0);

	cout<<ans<<endl;
	for(auto i: Ans)cout<<i<<endl;
}
