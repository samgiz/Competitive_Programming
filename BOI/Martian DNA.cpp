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
const int N = 200001;
int Cum[N], S[N], Req[N];

int main(){
	fastInputOutput;
	int n, k, r;
	cin>>n>>k>>r;
	fori(n)cin>>S[i];
	fori(r){
		int a, b;
		cin>>a>>b;
		Req[a]=b;
	}
	int rem = 0;
	fori(n)rem+=Cum[i]<Req[i];

	int ans = -1;

	int s=0, e=0;
	while(true){
		while(e<n&&rem){
			Cum[S[e]]++;
			if(Req[S[e]]==Cum[S[e]])rem--;
			e++;
		}
		if(e==n)break;
		while(rem==0){
			Cum[S[s]]--;
			if(Cum[S[s]]<Req[S[s]]){
				if(ans==-1||ans>e-s)ans=e-s;
				rem=1;
			}
			s++;
		}
	}

	if(ans==-1)cout<<"impossible";
	else cout<<ans;
}
