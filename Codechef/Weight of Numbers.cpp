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
const ll M = 1e9+7;
int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	while(t--){
		ll n, w;
		cin>>n>>w;
		n-=2;
		ll base=0;
		if(w>=0&&w<9)base = 9-w;
		if(w>-10&&w<0)base = 10+w;
		// 10^(n-2)
		ll mul = 10, ans = 1;
		for(int i=0; i<63; i++){
			if(n&(((ll)1)<<i))ans=ans*mul%M;
			mul=mul*mul%M;
		}
		cout<<ans*base%M<<endl;
	}
}