#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef int def; //default parameter for loops
#define repi(a) for(def i=0; i<(a); i++)
#define repii(a, b) for(def i=(a); i<(b); i++)
#define repj(a) for(def j=0; j<(a); j++)
#define repjj(a, b) for(def j=(a); j<(b); j++)
#define repk(a) for(def k=0; k<(a); k++)
#define repkk(a, b) for(def k=(a); k<(b); k++)
#define repe(a) for(def e=0; e<(a); e++)
#define repee(a, b) for(def e=(a); e<(b); e++)
#define repl(a) for(def l=0; l<(a); l++)
#define repll(a, b) for(def l=(a); l<(b); l++)

#define fastInputOutput ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define NM 300010

ll Tm[NM], Tp[NM];
ll n, a, b, c, d, start, len;
ll LeftSum[NM], LeftMin[NM], RightSum[NM], RightMin[NM];

ll popularity(ll a, ll b, ll i){
	if(Tp[i])return a;
	return -b;
}

int main(){
	// fastInputOutput;
	
	cin>>n>>a>>b>>c>>d>>st>>len;

	repi(n) cin>>Tm[i]>>Tp[i];
	LeftSum[0]=start+popularity(a, b, 0);
	LeftMin[0]=min(start, LeftSum[0]);
	repii(1, n){
		LeftSum[i]=LeftSum[i-1]+popularity(a, b, i);
		LeftMin[i]=min(LeftMin[i-1], LeftSum[i]);
	}
	repii(1, n){
		LeftSum[i]=LeftSum[i-1]+popularity(a, b, i);
		LeftMin[i]=min(LeftMin[i-1], LeftSum[i]);
	}
}
