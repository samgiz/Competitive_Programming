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

int main(){
	// fastInputOutput;
	int t;
	cin>>t;
	while(t--){
		string s;
		ll n;
		cin>>s>>n;
		ll sum = 0, cur=0, ans=0;
		for(auto i: s)
			sum+=(i=='a')-(i=='b');
		for(auto i: s){
			cur+=(i=='a')-(i=='b');
			if(cur<=0&&sum>0)
				ans+=max((ll)0, n+(cur-1)/sum);
			else if(cur>0&&sum<0)
				ans+=min(n, 1-(cur-1)/sum);
			else if(cur>0||sum==0)
				ans+=(cur>0)*n;
			// cerr<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
