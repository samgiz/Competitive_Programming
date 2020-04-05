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

vl V;
ll M[1010], S[1010], P[1010];

int main(){
	fastInputOutput;
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cout<<"Case #"<<test<<": ";
		ll r, b, c;
		cin>>r>>b>>c;
		ll as=0, bs=(((ll)1e18)<<1);
		fori(c)cin>>M[i]>>S[i]>>P[i];
		while(as!=bs){
			V.clear();
			ll mid=(as+bs)/2;
			ll sum = 0;
			fori(c){
				V.pb(max((ll)0, min(M[i], (mid-P[i])/S[i])));
			}
			sort(V.begin(), V.end(), greater<ll>());
			fori(r){
				sum+=V[i];
			}
			if(sum>=b)bs=mid;
			else as=mid+1;
		}
		cout<<as<<endl;
	}
}
