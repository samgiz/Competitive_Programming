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
const int N = 300001;
map<ll, ll>M[N];
int Color[N];
vector<int>E[N];
int n, m, k;

bool contains(ll a, ll b){
	while(b){
		if(b%k==a)return true;
		b/=k;
	}
	return false;
}

int main(){
	// fastInputOutput;
	
	cin>>n>>m>>k;
	k++;

	fori(n)cin>>Color[i];
	fori(m){
		int a, b;
		cin>>a>>b;
		E[a-1].pb(b-1);
		E[b-1].pb(a-1);
	}
	fori(n){
		M[i][0]=1;
	}
	fori(n){ // k=2
		ll ans = 0;
		ll num = 0;
		for(auto &t: E[i]){
			if(Color[t]==Color[i])continue;
			M[i][Color[t]]++;
		}
	}
	fori(n){ // k=3
		for(auto &t: E[i]){
			if(Color[t]==Color[i])continue;
			for(auto &num: M[t]){
				if(num.fi>0&&num.fi<k&&!contains(Color[i], num.fi))
					M[i][Color[t]+k*num.fi]+=num.se;
			}
			
		}
	}
	if(k>4){
		fori(n){ // k=4
			for(auto &t: E[i]){
				if(Color[t]==Color[i])continue;
				for(auto &num: M[t]){
					if(num.fi>k&&num.fi<k*k&&!contains(Color[i], num.fi))
						M[i][Color[t]+k*num.fi]+=num.se;
				}
				
			}
		}
	}

	if(k>5){
		fori(n){ // k=5
			for(auto &t: E[i]){
				if(Color[t]==Color[i])continue;
				for(auto &num: M[t]){
					if(num.fi>k*k&&num.fi<k*k*k&&!contains(Color[i], num.fi))
						M[i][Color[t]+k*num.fi]+=num.se;
				}
				
			}
		}
	}
	ll ans = 0;
	for(auto &i: M){
		for(auto &j: i)ans+=j.se;
	}
	cout<<ans-n;
}
