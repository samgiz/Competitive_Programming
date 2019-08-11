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

int Par[400010], Rank[400010];
int parent(int a){
	if(Par[a]!=a)return Par[a]=parent(Par[a]);
	return a;
}

int main(){
	// fastInputOutput;
	fori(400010)Par[i]=i;
	int n, m, q;
	cin>>n>>m>>q;
	int ans = n+m-1;
	fori(q){
		int a, b;
		cin>>a>>b;
		a = parent(a);
		b = parent(b+200002);
		if(a==b)continue;
		ans--;
		if(Rank[a]>Rank[b]){
			Par[b]=a;
		}
		else{
			if(Rank[a]==Rank[b])Rank[b]++;
			Par[a]=b;
		}
	}
	cout<<ans;
}
