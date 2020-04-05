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
double eps = 1e-9;
double W[101], H[101];
vector<pair<double, double>>cur, nw, tp;

double longest(int i){
	return sqrt(W[i]*W[i]+H[i]*H[i]);
}

int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	cout<<fixed;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		cur.clear();
		ll n, p;
		cin>>n>>p;
		double k = p;
		double mini=0, maxi=0;
		fori(n){
			cin>>W[i]>>H[i];
			k-=2*(W[i]+H[i]);
			int tp = 2*min(W[i], H[i]);
			H[i] = 2*sqrt(W[i]*W[i]+H[i]*H[i]);
			W[i]=tp;
		}
		cur.pb(mp(W[0], H[0]));
		forii(1, n){
			nw.clear();
			tp.clear();
			nw.pb(mp(W[i], H[i]));
			for(auto j: cur)nw.pb(mp(j.fi+W[i], j.se+H[i]));

			// The merging part. Most likely to not work
			int l=0, j=0;
			double s, e;
			if(cur[0].fi<nw[0].fi)s=cur[0].fi, e=cur[0].se;
			else s=nw[0].fi, e=nw[0].se;

			while(l<cur.size()||j<nw.size()){
				if(l<cur.size()&&cur[l].fi<=e+eps){ 
					// add cur[i] to current interval
					e = max(e, cur[l++].se);
				}
				else if(j<nw.size()&&nw[j].fi<=e+eps){ 
					// add nw[j] to current interval
					e = max(e, nw[j++].se);
				}
				else{
					// push new accumulated interval
					tp.pb(mp(s, e));
					// produce new interval
					if(j==nw.size()||(l<cur.size()&&cur[l].fi<nw[j].fi))s=cur[l].fi, e=cur[l].se;
					else s=nw[j].fi, e=nw[j].se;
				}
			}
			// add last interval
			tp.pb(mp(s, e));
			// copy tp to cur
			cur.swap(tp);
		}
		double ans = p-k;
		for(auto i: cur){
			if(i.fi-eps<=k)ans = max(ans, p+min(0.0, i.se-k));
		}
		cout<<setprecision(10)<<ans<<endl;
		// for(auto i: cur)cerr<<i.fi<<" "<<i.se<<endl;
	}
}
