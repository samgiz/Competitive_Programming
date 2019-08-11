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

int A[N], B[N];

int main(){
	// fastInputOutput;
	ll n, m;
	cin>>n>>m;
	fori(n)cin>>A[i]>>B[i];
	sort(A, A+n);
	sort(B, B+n);
	ll ans = n*m;
	fori(m){
		int c, d;
		cin>>c>>d;
		int a=0, b=n;
		while(a!=b){
			int mid = (a+b)/2;
			if(d<A[mid])b = mid;
			else a = mid+1;
		}
		// cerr<<i<<" "<<a<<" ";
		ans-=n-a;
		a=-1, b=n-1;
		while(a!=b){
			int mid = (a+b+1)/2;
			if(c>B[mid])a = mid;
			else b = mid-1;
		}
		// cerr<<a<<" "<<endl;
		ans-=a+1;
	}
	cout<<ans;
}
