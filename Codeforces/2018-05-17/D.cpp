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
pll A[N];
ll Par[N], Sz[N];
ll diffs = 0;
map<ll, ll>Sizes;

ll parent(int p){
	if(Par[p]==p)return p;
	return Par[p]=parent(Par[p]);
}

void join(ll a, ll b){
	a = parent(a);
	b = parent(b);
	Sizes[Sz[a]]--;
	Sizes[Sz[b]]--;
	if(Sizes[Sz[a]]==0)diffs--;
	if(Sz[a]!=Sz[b] && Sizes[Sz[b]]==0)diffs--;

	if(Sz[a]>Sz[b]){
		Par[b]=a;
		Sz[a]+=Sz[b];
		if(Sizes[Sz[a]]==0)diffs++;
		Sizes[Sz[a]]++;
	}
	else{
		Par[a]=b;
		Sz[b]+=Sz[a];
		if(Sizes[Sz[b]]==0)diffs++;
		Sizes[Sz[b]]++;
	}
	
}

int main(){
	fastInputOutput;
	int n;
	cin>>n;
	fori(n){
		cin>>A[i].fi;
		A[i].se=i;
	}
	sort(A, A+n);
	fori(n)Sz[i]=0;
	fori(n)Par[i]=i;

	ll k=-1;
	ll ans = 0;

	fori(n){
		if(Sizes[1]==0)diffs++;
		Sizes[1]++;
		Sz[A[i].se]=1;
		ll s = A[i].se;
		
		if(s-1>=0 && Sz[s-1]>0)join(s-1, s);
		if(s+1<n && Sz[s+1]>0)join(s, s+1);

		if(diffs == 1){
			ll am = (i+1)/Sz[parent(s)];
			if(am > ans){
				ans = am;
				k = A[i].fi+1;
			}
		}
		// fori(8)cerr<<i<<" "<<parent(i)<<" "<<Sz[parent(i)]<<endl;
		// for(auto i: Sizes){
		// 	if(i.se)cerr<<i.fi<<" ";
		// }cerr<<endl;
		// cerr<<Sz[parent(s)]<<" "<<diffs<<"   aaaaa"<<endl;
		// cerr<<endl;
	}
	cout<<k;
	// cerr<<endl<<ans;
}
