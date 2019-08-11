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

int M = 1007;

vector<int>E[20];
set<int> SCC[20];
int Index[20], Lowlink[20];
bool Vis[20], onStack[20];
set<int>ToVisit;
int DP[20][10];
int last;

stack<int>S;
int ind = 0;

void components(int cur){
	Index[cur]=ind;
	Lowlink[cur]=ind++;
	S.push(cur);
	onStack[cur]=true;
	Vis[cur]=true;
	for(auto i: E[cur]){
		if(!Vis[i]){
			cerr<<"a";
			components(i);
			Lowlink[cur]=min(Lowlink[i], Lowlink[cur]);
		}
		else if(onStack[i]){
			Lowlink[cur]=min(Lowlink[i], Lowlink[cur]);
		}
	}

	if(Lowlink[cur]==Index[cur]){
		last = Lowlink[cur];
		ToVisit.insert(last);
		while(S.size()){
			for(auto i: E[S.top()]){
				if(Lowlink[i]!=last){
					ToVisit.erase(Lowlink[i]);
					SCC[last].insert(Lowlink[i]);
				}
			}
			onStack[S.top()]=false;
			if(S.top()==cur)break;
			S.pop();
		}
	}
}

void dp(int cur){
	if(DP[cur][0]!=-1)return;
	for(auto i: SCC[cur])dp(i);
	fori(10){
		DP[cur][i]=1;
		for(auto j: SCC[cur]){
			DP[cur][i]=(DP[cur][i]*DP[j][i])%M;
		}
		if(i>0)DP[cur][i]=(DP[cur][i]+DP[cur][i-1])%M;
	}
}

int main(){
	// fastInputOutput;
	// Wrong D Palgorithm
	int n, m;
	cin>>n>>m;
	fori(m){
		int x, y;
		cin>>x>>y;
		E[y].pb(x);
	}
	fori(20)Index[i]=-1;
	fori(20){
		forj(10)DP[i][j]=-1;
	}
	fori(n){
		if(!Vis[i])components(i);
	}
	dp(last);
	int ans = 1;
	for(auto i: ToVisit){
		dp(i);
		ans = (ans*DP[i][9])%M;
	}
	cout<<ans<<endl;
	while(S.size()){
		cerr<<S.top()<<" ";
		S.pop();
	}
	cerr<<endl<<last;
}
