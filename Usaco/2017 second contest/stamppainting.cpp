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

ll M = 1e9+7;

int main(){
	// fastInputOutput;
	ifstream cin("spainting.in");
	ofstream cout("spainting.out");
	ll n, m, k;
	cin>>n>>m>>k;
	ll Pow[n+1];
	Pow[0]=1;
	repii(1, n+1){
		Pow[i]=(Pow[i-1]*m)%M;
	}

	ll Flawed[n+1];
	Flawed[0]=1;
	repii(1, n+1){
		Flawed[i]=(Flawed[i-1]*m)%M;
		if(i==k)Flawed[i]=((Flawed[i]-Flawed[i-k]*m)%M+M)%M;
		if(i>k)Flawed[i=]((Flawed[i]-Flawed[i-k]*(m-1))%M+M)%M;
	}
	// repi(n+1)cerr<<Flawed[i]<<" ";cerr<<endl;
	// cerr<<Pow[n]<<" "<<Flawed[n]<<endl;
	cout<<(Pow[n]-Flawed[n]+M)%M<<endl;
}
