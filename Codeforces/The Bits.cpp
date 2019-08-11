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

ll OO=0, IO=0, OI=0, II=0;

int main(){
	// fastInputOutput;
	int n;
	cin>>n;
	string a, b;
	cin>>a>>b;

	fori(n){
		if(a[i]=='0'&&b[i]=='1')OI++;
		if(a[i]=='0'&&b[i]=='0')OO++;
		if(a[i]=='1'&&b[i]=='1')II++;
		if(a[i]=='1'&&b[i]=='0')IO++;
	}

	ll ans = OO*(IO+II) + OI*IO;
	cout<<ans;
}
