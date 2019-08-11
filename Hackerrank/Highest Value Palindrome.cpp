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

bool Changed[100001];

int main(){
	// fastInputOutput;
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	Changed[n/2] = true;
	fori(n/2){
		Changed[i]=s[i]!=s[n-1-i];
		if(Changed[i])s[i]=max(s[i], s[n-1-i]), s[n-1-i]=max(s[i], s[n-1-i]), k--;
	}
	// cerr<<s<<endl;
	// cerr<<Changed[0]<<" "<<Changed[1]<<endl;
	if(k<0){
		cout<<-1;
		exit(0);
	}
	cerr<<k<<" "<<Changed[0]<<endl;
	fori((n+1)/2){
		if(s[i]=='9')continue;
		if(Changed[i]&&k>0)s[i]='9', s[n-1-i]='9', k--;
		else if(k>1)s[i]='9', s[n-1-i]='9', k-=2;
	}
	cout<<s;
}
