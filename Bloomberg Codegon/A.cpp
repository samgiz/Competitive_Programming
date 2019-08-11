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

ll Min[1000001];
ll A[100001];

int n;
ll Bin1(ll v){
	if(v<A[0])return 5; 
	ll a=0, b=n-1;
	while(a!=b){
		ll mid=(a+b+1)/2;
		if(A[mid]>=v)b=mid-1;
		else a=mid;
	}
	return 5+Min[a];
}

ll Bin2(ll v){
	if(v<A[0])return 20; 
	ll a=0, b=n-1;
	while(a!=b){
		ll mid=(a+b+1)/2;
		if(A[mid]>=v)b=mid-1;
		else a=mid;
	}
	return 20+Min[a];
}

ll Bin3(ll v){
	if(v<A[0])return 50;
	ll a=0, b=n-1;
	while(a!=b){
		ll mid=(a+b+1)/2;
		if(A[mid]>=v)b=mid-1;
		else a=mid;
	}
	return 50+Min[a];
}

int main(){
	// fastInputOutput;
	cin>>n;
	
	repi(n)cin>>A[i];
	
	Min[0]=2;
	repii(1, n){
		Min[i]=Min[i-1]+2;
		Min[i]=min(Min[i], Bin1(A[i]-60));
		Min[i]=min(Min[i], Bin2(A[i]-60*6));
		Min[i]=min(Min[i], Bin3(A[i]-60*24));
	}


	cout<<2<<endl;
	repii(1, n){
		cout<<Min[i]-Min[i-1]<<endl;
	}
}
