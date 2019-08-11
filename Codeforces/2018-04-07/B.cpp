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

ll A[1001], B[1001];
pll C[1001];

int main(){
	// fastInputOutput;
	ll n, k, k2;
	cin>>n>>k>>k2;
	fori(n)cin>>A[i];
	fori(n)cin>>B[i];
	k+=k2;
	fori(n)C[i] = mp(min(A[i], B[i]), max(A[i], B[i]));
	sort(C, C+n, [](pii a, pii b){return (a.se-a.fi)>(b.se-b.fi);});
	for(int i=1; i<n; i++){
		while((C[i].se-C[i].fi)<C[i-1].se-C[i-1].fi){
			forj(i){
				k--;
				C[j].se--;
				if(k==0)break;
			}
			if(k==0)break;
		}
		if(k==0)break;
	}
	while(C[n-1].se-C[n-1].fi && k){
		forj(n){
			k--;
			C[j].se--;
			if(k==0)break;
		}
		if(k==0)break;
	}
	if(k>0){
		if(k%2)cout<<1;
		else cout<<0;
		exit(0);
	}
	ll s = 0;
	fori(n)s+=(C[i].fi-C[i].se)*(C[i].fi-C[i].se);
	cout<<s;
}
