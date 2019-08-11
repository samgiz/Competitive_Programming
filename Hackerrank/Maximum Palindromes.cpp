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
const int M = 1e9+7;

ll fact[N], inv[N];
ll S[N][26];

// returns b, s.t. ab = 1 (mod M)
ll inverse(ll a){
	ll power=M-2, b = 1;
	while(power){
		// cerr<<power<<" "<<a<<" "<<b<<endl;
		if(power&1)b=(b*a)%M;
		a=(a*a)%M;
		power>>=1;
	}
	return b;
}

int main(){
	fastInputOutput;
	// ofstream cout("txt");
	fact[0]=1;
	fori(N-1)fact[i+1]=(fact[i]*(i+1))%M;
	fori(N)inv[i]=inverse(fact[i]);
	// cerr<<inverse(1)<<" "<<inverse(2);

	string s;
	cin>>s;
	fori(s.size()){
		forj(26)S[i+1][j]=S[i][j];
		S[i+1][s[i]-'a']++;
	}

	int q;
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		a--;
		ll ans = 1;
		ll mid = 0, len = 0;
		fori(26){
			int num = (S[b][i]-S[a][i])/2;
			len+=num;
			ans=(ans*inv[num])%M;
			// cerr<<ans<<endl;
			mid+=(S[b][i]-S[a][i])%2;
		}
		ans=(ans*(mid?mid:1))%M;
		ans=(ans*fact[len])%M;
		cout<<ans<<endl;
	}
}
