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

const ll Z = 314160;
const ll M = 1e9+7;
const ll N = 500010;

ll Two[N];

int main(){
	// fastInputOutput;
	string a, b;
	cin>>a>>b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	Two[0]=1;
	fori(N-1)Two[i+1] = (Two[i]<<1)%M;
	ll cnt = 0;
	ll ans = 0;
	fori(a.size())cnt+=(i<b.size()?b[i]=='1':0), ans=(ans+((Z-cnt)*(a[i]=='1')+cnt*(a[i]=='0'))*Two[i])%M;
	forii(a.size(), b.size())cnt+=(b[i]=='1'), ans=(ans+cnt*Two[i])%M;
	forii(max(a.size(), b.size()), Z)ans=(ans+Two[i]*cnt)%M;
	forii(Z, Z+b.size())cnt-=(b[i-Z]=='1'), ans=(ans+Two[i]*cnt)%M;

	cout<<ans;
}
