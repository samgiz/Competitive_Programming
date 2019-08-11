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

vi E[100001];
ll Odd[100001], Even[100001];
bool Vis[100001];

void count(int cur){
	Vis[cur] = 1;
	Odd[cur]=1;
	for(auto i: E[cur]){
		if(Vis[i])continue;
		count(i);
		ll a=0, b=0;
		if(Even[i] && Odd[cur]){
			a = Even[i]+Odd[cur];
		}
		if(Even[cur] && Odd[i]){
			a = max(a, Odd[i]+Even[cur]-1);
		}

		if(Even[i] && Even[cur]){
			b = Even[i]+Even[cur];
		}
		if(Odd[cur] && Odd[i]){
			b = max(b, Odd[i]+Odd[cur]-1);
		}
		Odd[cur] = a;
		Even[cur] = b;
	}
}

int main(){
	fastInputOutput;
	int n;
	cin>>n;
	fori(n-1){
		int u, v;
		cin>>u>>v;
		E[u].pb(v);
		E[v].pb(u);

	}

	count(1);
	cout<<Even[1]-1<<endl;
	// for(int i=1; i<5; i++){
	// 	cerr<<Odd[i]<<" "<<Even[i]<<endl;
	// }
}
