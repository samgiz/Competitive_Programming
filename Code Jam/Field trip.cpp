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

pll A[10010];

int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		int n;
		cin>>n;
		fori(n)cin>>A[i].fi>>A[i].se;
		ll a, b;
		a = 0;
		b = (((ll)1)<<34);
		while(a!=b){
			ll mid = (a+b)/2;
			ll rl = -(((ll)1)<<34); // row left
			ll rr = (((ll)1)<<34); // row right
			ll cl = -(((ll)1)<<34); // column left
			ll cr = (((ll)1)<<34); // column right
			fori(n){
				rl = max(rl, A[i].fi-mid);
				rr = min(rr, A[i].fi+mid);
				cl = max(cl, A[i].se-mid);
				cr = min(cr, A[i].se+mid);
			}
			if(rl<=rr&&cl<=cr)b = mid;
			else a=mid+1;
		}
		cout<<a<<endl;
	}

}
